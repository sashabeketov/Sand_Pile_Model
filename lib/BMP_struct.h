#pragma once
#include <cstdint>

#pragma pack(push, 1)

struct BMPHeader{

    uint16_t signature_;
    uint32_t fileSize_;
    uint32_t reserved_;
    uint32_t dataOffset_;
    uint32_t headerSize_;
    uint32_t width_;
    uint32_t height_;
    uint16_t planes_;
    uint16_t bpp_;
    uint32_t compression_;
    uint32_t dataSize_;
    uint32_t hRes_;
    uint32_t vRes_;
    uint32_t colors_;
    uint32_t importantColors_;

    BMPHeader();

    ~BMPHeader();
};

struct RGBQUAD{
    uint8_t blue_;
    uint8_t green_;
    uint8_t red_;
    uint8_t reserved_;

    RGBQUAD(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved);

    ~RGBQUAD();
};

#pragma pack(pop)

extern RGBQUAD colorTable[16];