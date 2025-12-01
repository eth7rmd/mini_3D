#ifndef DG_WAVE_FILE_LOADER_H_
#define DG_WAVE_FILE_LOADER_H_

typedef struct {
    unsigned int nSamplesPerSec;
    unsigned short nChannels;
    unsigned short wBitsPerSample;
    unsigned char* data;
} WAVFile;

unsigned char* audio_read_wav_file(const char* path, unsigned short* nChannels, unsigned int* nSamplesPerSec, unsigned short* wBitsPerSample);

#endif
