#ifndef DG_SOUND_BLASTER_H_
#define DG_SOUND_BLASTER_H_

#include <AL/al.h>
#include <AL/alc.h>

typedef struct {
    ALCdevice* device;
    ALCcontext* context;
} SoundBlaster;

int audio_sound_blaster_init(void);
int audio_sound_blaster_shutdown(void);

int audio_read_wav_file(const char* path);

///// Init
// ALCdevice *device = alcOpenDevice(NULL);
// ALCcontext *ctx = alcCreateContext(device, NULL);
// alcMakeContextCurrent(ctx);

///// Use OpenAL here...
// ALuint buffer, source;
// alGenBuffers(1, &buffer);
// alGenSources(1, &source);

///// ... load audio, play, etc.

///// Cleanup
// alDeleteSources(1, &source);
// alDeleteBuffers(1, &buffer);
// alcMakeContextCurrent(NULL);
// alcDestroyContext(ctx);
// alcCloseDevice(device);

#endif /*DG_SOUND_BLASTER_H_*/
