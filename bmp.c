#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BitMapFileHeader {
    unsigned type : 16;
    unsigned fileSize : 32;
    unsigned reserved : 32;
    unsigned offset : 32;
} BitMapFileHeader;

typedef struct BitMapInfoHeader {
    unsigned infoSize : 32;
    unsigned width : 32;
    unsigned height : 32;
    unsigned planes : 16;
    unsigned depth : 16;
    unsigned compression : 32;
    unsigned imageSize : 32;
    unsigned xPixelsPerMetre : 32;
    unsigned yPixelsPerMetre : 32;
    unsigned numColours : 32;
    unsigned numImportantColours : 32;
} BitMapInfoHeader;

typedef struct BitMap {
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;
} BitMap;

void touchBitMap(const char* fileName) {
    const char* fileType = strrchr(fileName, '.');

    if (fileType == NULL || strncmp(fileType, ".bmp", 5) != 0) {
        fprintf(stderr, "Incorrect file type %s\n", fileType);
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(fileName, "w");

    BitMap map;
    map.fileHeader.type = "BM";
    map.fileHeader.fileSize = 100;
    map.fileHeader.reserved = 0;
    map.fileHeader.offset = 0;
    map.infoHeader.infoSize = 100;
    map.infoHeader.width = 100;
    map.infoHeader.height = 100;
    map.infoHeader.planes = 0;
    map.infoHeader.depth = 10;
    map.infoHeader.compression = 0;
    map.infoHeader.imageSize = 100;
    map.infoHeader.xPixelsPerMetre = 1000;
    map.infoHeader.yPixelsPerMetre = 1000;
    map.infoHeader.numColours = 3;
    map.infoHeader.numImportantColours = 3;

    fwrite(map, 1, 100, file);

    fclose(file);
}
