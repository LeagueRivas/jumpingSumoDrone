EXEC_NAME=JumpingSumoPiloting

#ARDrone SDK Directory
SDK_DIR=/home/user/sdk/out/Unix-base/staging/usr

IDIR=./
CC=gcc
CFLAGS=-I$(IDIR) -I $(SDK_DIR)/include \
`pkg-config --cflags opencv`

#OpenCV Library Directory (Including OpenCV2)
#CPPFLAGS= -I/home/user/opencv-2.4.13/include/opencv \
-I/home/user/opencv-2.4.13/include/opencv2

#Libraries
#LDLIBS= -lopencv_core -lopencv_imgproc -lopencv_highgui \
		 -lopencv_ml -lopencv_video -lopencv_features2d \
	 -lopencv_calib3d -lopencv_objdetect \
	 -lv4l1 -lv4l2 -lv4lconvert -lopencv_imgcodecs

LDLIBS = `pkg-config --libs opencv`
OBJDIR=obj
LDIR = $(SDK_DIR)/lib

EXTERNAL_LIB=-lncurses -ljson

LIBS=-L$(SDK_DIR)/lib -larcommands -larcontroller -lardiscovery -larmedia -larnetwork -larnetworkal -larsal -larstream -larstream2 $(EXTERNAL_LIB)
LIBS_DBG=-L$(SDK_DIR)/lib -larsal_dbg -larcommands_dbg -larnetwork_dbg -larnetworkal_dbg -lardiscovery_dbg -larstream_dbg $(EXTERNAL_LIB)

#Dependencies
_DEPS = JumpingSumoPiloting.h ihm.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = JumpingSumoPiloting.o ihm.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

FIFO = video_fifo

all: $(EXEC_NAME)
	@[ -p $(FIFO) ] || mkfifo $(FIFO)

$(OBJDIR)/%.o: %.c $(DEPS)
	@ [ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	@ $(CC) -c -o $@ $< $(CFLAGS)

$(EXEC_NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) $(LDLIBS)

.PHONY: clean

clean:
	@ rm -f $(OBJDIR)/*.o *~ core $(INCDIR)/*~
	@ rm -rf $(OBJDIR)
	@ rm -r $(EXEC_NAME)

run:
	LD_LIBRARY_PATH=$(LDIR) ./$(EXEC_NAME)
