/***********************************************************************************************************************
*                                                                                                                      *
* wfmserver                                                                                                            *
*                                                                                                                      *
* Copyright (c) 2012-2021 Andrew D. Zonenberg                                                                          *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

#ifndef wfmserver_h
#define wfmserver_h

#include "../../lib/log/log.h"
#include "../../lib/xptools/Socket.h"

#ifdef _WIN32
#include <windows.h>
#include <shlwapi.h>
#endif

#include <thread>
#include <map>
#include <mutex>

#include <digilent/waveforms/dwf.h>

extern Socket g_scpiSocket;
extern Socket g_dataSocket;

void ScpiServerThread();
void WaveformServerThread();

extern HDWF g_hScope;

extern std::string g_model;
extern std::string g_serial;
extern std::string g_fwver;

extern size_t g_numAnalogInChannels;
extern volatile bool g_waveformThreadQuit;

extern size_t g_captureMemDepth;
extern size_t g_memDepth;
extern std::map<size_t, bool> g_channelOnDuringArm;
extern std::map<size_t, bool> g_channelOn;

/*
extern bool g_msoPodEnabled[2];
extern bool g_msoPodEnabledDuringArm[2];
extern int16_t g_msoPodThreshold[2][8];
extern PICO_DIGITAL_PORT_HYSTERESIS g_msoHysteresis[2];

*/
extern int64_t g_sampleInterval;
extern int64_t g_sampleIntervalDuringArm;
/*
extern std::map<size_t, double> g_offsetDuringArm;

extern size_t g_triggerSampleIndex;
extern size_t g_triggerChannel;
extern float g_triggerVoltage;
*/
extern bool g_triggerArmed;
extern bool g_triggerOneShot;
extern bool g_memDepthChanged;

extern std::mutex g_mutex;

/*
void Stop();
*/
void Start(bool force = false);
/*PICO_STATUS StartInternal();
void UpdateTrigger(bool force = false);
void UpdateChannel(size_t chan);

extern bool g_lastTriggerWasForced;
*/

#endif