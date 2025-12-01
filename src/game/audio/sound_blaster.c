#include "sound_blaster.h"

#include <stdio.h>


int audio_sound_blaster_init(void)
{
    return 0;
}

int audio_sound_blaster_shutdown(void)
{
    return 0;
}




int audio_read_wav_file(const char* path)
{
    FILE* f = fopen(path, "rb");
    if (f == NULL) {
        return 1;
    }

    unsigned char riff_part[5];
    fread(riff_part, 1, sizeof(riff_part) - 1, f);
    riff_part[4] = '\0';

    printf("RIFF : %s\n", riff_part);
    
    if (f) fclose(f);
    return 0;
}

