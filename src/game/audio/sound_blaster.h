#ifndef DG_SOUND_BLASTER_H_
#define DG_SOUND_BLASTER_H_

typedef enum {
    SOUND_EXAMPLE,
    SOUND_PUNCH,
    SOUND_COUNT
} SoundID;

int sound_blaster_init(void);
void sound_blaster_shutdown(void);
void sound_blaster_play_sound(SoundID id);

#endif /*DG_SOUND_BLASTER_H_*/
