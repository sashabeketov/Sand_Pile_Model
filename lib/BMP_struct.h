#pragma once

struct BMPHeader{
    BMPHeader(uint32_t width, uint32_t height, uint32_t fileSize);

    ~BMPHeader();
};

struct RGBQUAD{
    RGBQUAD(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved);

    ~RGBQUAD();
};

extern RGBQUAD colorTable[16];