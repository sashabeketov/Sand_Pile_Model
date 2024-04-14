#include "BMP_struct.h"

#pragma pack(push, 1)

BMPHeader::BMPHeader() {
    signature_ = 0x4D42; // Сигнатура "BM" - 2 bytes
    fileSize_ = 0; // Размер файла - 4 bytes
    reserved_ = 0; // всегда 0 - 4 bytes
    dataOffset_ = 54 + 64; // Смещение до начала данных - 4 bytes
    headerSize_ = 40; // Размер заголовка - 4 bytes
    width_ = 0; // Ширина изображения - 4 bytes
    height_ = 0; // Высота изображения - 4 bytes
    planes_ = 1; // Количество плоскостей (обычно 1) - 2 bytes
    bpp_ = 4; // Бит на пиксель - 2 bytes
    compression_ = 0; // Сжатие - 4 bytes
    dataSize_ = 0; // Размер данных - 4 bytes
    hRes_ = 0; // - 4 bytes
    vRes_ = 0; // - 4 bytes
    colors_ = 0; // - 4 bytes
    importantColors_ = 0; // - 4 bytes
}

BMPHeader::~BMPHeader() = default;

RGBQUAD::RGBQUAD(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved) {
    blue_ = blue;
    green_ = green;
    red_ = red;
    reserved_ = reserved;
}

#pragma pack(pop)

RGBQUAD::~RGBQUAD() = default;

RGBQUAD colorTable[16] = {
        {0x00, 0x00, 0x00, 0x00}, // Черный
        {0x80, 0x00, 0x00, 0x00}, // Темно-синий
        {0x00, 0x80, 0x00, 0x00}, // Темно-зеленый
        {0x80, 0x80, 0x00, 0x00}, // Темно-голубой
        {0x00, 0x00, 0x80, 0x00}, // Темно-красный
        {0x80, 0x00, 0x80, 0x00}, // Фиолетовый
        {0x00, 0x80, 0x80, 0x00}, // Зеленовато-желтый
        {0x80, 0x80, 0x80, 0x00}, // Серый
        {0xC0, 0xC0, 0xC0, 0x00}, // Светло-серый
        {0xFF, 0x00, 0x00, 0x00}, // Синий
        {0x00, 0xFF, 0x00, 0x00}, // Зеленый
        {0xFF, 0xFF, 0x00, 0x00}, // Голубой
        {0x00, 0x00, 0xFF, 0x00}, // Красный
        {0xDD, 0x05, 0xFF, 0x00}, // Розовый
        {0x00, 0xFF, 0xFF, 0x00}, // Желтый
        {0xFF, 0xFF, 0xFF, 0x00}  // Белый
};



