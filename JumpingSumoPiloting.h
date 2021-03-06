/*
    Copyright (C) 2014 Parrot SA

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the 
      distribution.
    * Neither the name of Parrot nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written
      permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
    OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
*/

#ifndef _JUMPINGSUMO_PILOTING_H_
#define _JUMPINGSUMO_PILOTING_H_

#include <ihm.h>

#include <libARController/ARController.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

// called when the state of the device controller has changed
void stateChanged (eARCONTROLLER_DEVICE_STATE newState, eARCONTROLLER_ERROR error, void *customData);

// called when a command has been received from the drone
void commandReceived (eARCONTROLLER_DICTIONARY_KEY commandKey, ARCONTROLLER_DICTIONARY_ELEMENT_t *elementDictionary, void *customData);

// IHM updates from commands
void batteryStateChanged (uint8_t percent);

// called to configure the video stream decoder
eARCONTROLLER_ERROR decoderConfigCallback (ARCONTROLLER_Stream_Codec_t codec, void *customData);

// called when a streaming frame has been received
eARCONTROLLER_ERROR didReceiveFrameCallback (ARCONTROLLER_Frame_t *frame, void *customData);

/* IHM callbacks: */
void onInputEvent (eIHM_INPUT_EVENT event, void *customData);
int customPrintCallback (eARSAL_PRINT_LEVEL level, const char *tag, const char *format, va_list va);

#endif /* _JUMPINGSUMO_PILOTING_H_ */

// Detection Function
void detectObject (ARCONTROLLER_Device_t *deviceController);

// openCV functions Begin
int validateImage(IplImage *imgOriginal);

void createTrackbar(int iLowH, int iHighH, int iLowS, int iHighS, int iLowV, int iHighV);

void displayWindows(IplImage *imgOriginal, CvMat *imgThresholded);
// openCV functions End


//movement functions beign
void stopMovement(ARCONTROLLER_Device_t *deviceController);

void moveForward(ARCONTROLLER_Device_t *deviceController);

void turnRight(ARCONTROLLER_Device_t *deviceController);

void turnLeft(ARCONTROLLER_Device_t *deviceController);

void quickTurnRight(ARCONTROLLER_Device_t *deviceController);
//movement functions end










