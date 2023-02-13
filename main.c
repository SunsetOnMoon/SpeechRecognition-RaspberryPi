//
// Created by artsem on 12.2.23.
//
#include "Libs/Microphone/wav.h"
#include <stdio.h>
#include <alsa/asoundlib.h>

int main()
{
    WaveHeader *hdr;
    hdr = genericWAVHeader(44100, 16, 2);
    FILE *file;
    int fd;
    fd = open("test.wav", O_WRONLY);
    writeWAVHeader(fd, hdr);
    printf("Start recording...\n");
    recordWAV("test.wav", hdr, 10000);
    printf("End recording\n");

    return 0;
}
