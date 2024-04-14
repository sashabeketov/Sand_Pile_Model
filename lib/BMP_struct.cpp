#include <cstdint>
#include "BMP_struct.h"

#pragma pack(push, 1)

BMPHeader::BMPHeader(uint32_t width, uint32_t height, uint32_t fileSize) {
    uint16_t signature = 0x4D42; // Сигнатура "BM" - 2 bytes
    uint32_t fileSize_ = fileSize; // Размер файла - 4 bytes
    uint32_t reserved = 0; // всегда 0 - 4 bytes
    uint32_t dataOffset = 54; // Смещение до начала данных - 4 bytes
    uint32_t headerSize = 40; // Размер заголовка - 4 bytes
    uint32_t width_ = width; // Ширина изображения - 4 bytes
    uint32_t height_ = height; // Высота изображения - 4 bytes
    uint16_t planes = 1; // Количество плоскостей (обычно 1) - 2 bytes
    uint16_t bpp = 4; // Бит на пиксель - 2 bytes
    uint32_t compression = 0; // Сжатие - 4 bytes
    uint32_t dataSize = 0; // Размер данных - 4 bytes
    uint32_t hRes = 0; // - 4 bytes
    uint32_t vRes = 0; // - 4 bytes
    uint32_t colors = 0; // - 4 bytes
    uint32_t importantColors = 0; // - 4 bytes
}

BMPHeader::~BMPHeader() = default;

#pragma pack(pop)

RGBQUAD::RGBQUAD(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved) {
    blue;
    green;
    red;
    reserved;
}

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
        {0xFF, 0x05, 0xB8, 0x00}, // Розовый
        {0x00, 0xFF, 0xFF, 0x00}, // Желтый
        {0xFF, 0xFF, 0xFF, 0x00}  // Белый
};

//int main() {
//    My_Vector<uint8_t> pixelData;
//
//
//    BMPHeader header{};
//    header.signature = 0x4D42;
//    header.fileSize = sizeof(BMPHeader) + 256 * 256 / 2;
//    header.reserved = 0;
//    header.dataOffset = 54;
//    header.headerSize = 40;
//    header.width = 256;
//    header.height = 256;
//    header.planes = 1;
//    header.bpp = 4;
//    header.compression = 0;
//    header.dataSize = 0;
//    header.hRes = 0;
//    header.vRes = 0;
//    header.colors = 0;
//    header.importantColors = 0;

//    std::ofstream file("/Users/alex/Desktop/output.bmp", std::ios::binary);
//    file.write(reinterpret_cast<char*>(&header), sizeof(header));
//    for (int i = 0; i < 32768; i++) {
//        if (i % 2 == 0) {
//            pixelData.push_back(0x6B);
//        } else {
//            pixelData.push_back(0xFE);
//        }
//
//    }
//    file.write(reinterpret_cast<char*>(colorTable), sizeof(colorTable));
//    file.write(reinterpret_cast<char*>(pixelData.data()), pixelData.size());
//    file.close();
//    return 0;



