#include "sound_blaster.h"
#include "game/loaders/wave_file.h"
#include <assert.h>
#include <stdlib.h>
#include <AL/al.h>
#include <AL/alc.h>

// NOTE: Only works on arrays, not pointers!
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static ALuint g_al_buffer;

static int internal_audio_openal_init(const char* device)
{
    ALCdevice* Device;
    ALCcontext* Context;
    Device = alcOpenDevice(device);
    if (Device == NULL) {
        return 1;
    }

    Context = alcCreateContext(Device, NULL);
    alcMakeContextCurrent(Context);

    return 0;
}

static void internal_audio_openal_shutdown(void)
{
    alDeleteBuffers(1, &g_al_buffer);

    ALCdevice* Device;
    ALCcontext* Context;
    Context=alcGetCurrentContext();
    Device=alcGetContextsDevice(Context);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(Context);
    alcCloseDevice(Device);
}

void sound_blaster_play_sound()
{

}

void sound_blaster_load_wav(WAVFile* wave)
{
    // Determine format
    // For 8-bit mono: AL_FORMAT_MONO8
    // For 16-bit mono: AL_FORMAT_MONO16
    // For 8-bit stereo: AL_FORMAT_STEREO8
    // For 16-bit stereo: AL_FORMAT_STEREO16
    ALenum format;
    if (wave->nChannels == 1 && wave->wBitsPerSample == 8)        
        format = AL_FORMAT_MONO8;
    else if (wave->nChannels == 1 && wave->wBitsPerSample == 16)
        format = AL_FORMAT_MONO16;
    else if (wave->nChannels == 2 && wave->wBitsPerSample == 8)
        format = AL_FORMAT_STEREO8;
    else if (wave->nChannels == 2 && wave->wBitsPerSample == 16)
        format = AL_FORMAT_STEREO16;
    else assert(0 && "[OPEN_AL] Format not supported.");

    alBufferData(g_al_buffer, format, wave->data, wave->data_size, wave->nSamplesPerSec);
    ALenum error;
    if ((error = alGetError()) != AL_NO_ERROR) {
        assert(0 && "[OPEN_AL] alBuffer data failed.");
    }

}


int sound_blaster_init(void)
{
    if (internal_audio_openal_init(NULL)) {
        return 1;
    }

    alGetError();
    alGenBuffers(1, &g_al_buffer);

   // alBufferData(g_al_buffer, AL_FORMAT_MONO16, pcmData, dataSize, sampleRate);

    return 0;
}

void sound_blaster_shutdown(void)
{
    internal_audio_openal_shutdown();
}





