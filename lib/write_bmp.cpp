#include "write_bmp.h"

#pragma pack(push, 1)

#include "BMP_struct.h"

#pragma pack(pop)

void WriteBMP(const std::string& path_name, const std::string& bmp_file_name, std::vector<char>& bit_map, uint32_t width, uint32_t height) {
    BMPHeader bmp;
    bmp.width_ = width;
    bmp.height_ = width;


    int rowSize = ((bmp.bpp_ * bmp.width_ + 31) / 32) * 4;
    bmp.fileSize_ = 54 + 16 * 4 + height * width / 2 + rowSize - width / 2;


    std::ofstream file(path_name + bmp_file_name, std::ios::binary);
    file.write((char*)&bmp, sizeof(bmp));

    RGBQUAD palette[16] = {
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
    file.write(reinterpret_cast<const char*>(&palette), sizeof(palette));

    int width_c = -1;

    for (int x = 0; x < bit_map.size(); x++){
        width_c++;
        if (width % 2 != 0){
            if (width_c >= width / 2 + 1) {
                for (int i = rowSize - width / 2 - 1; i > 0; --i) {
                    char padding = 0;
                    file.write(&padding, 1);
                }
                width_c = -1;
                x--;
            } else {
                file.write(&bit_map[x], 1);
            }
            if (x == bit_map.size() - 1) {
                for (int i = rowSize - width / 2 - 1; i > 0; --i) {
                    char padding = 0;
                    file.write(&padding, 1);
                }
            }
        } else {
            if (width_c >= width / 2) {
                for (int i = rowSize - width / 2; i > 0; --i) {
                    char padding = 0;
                    file.write(&padding, 1);
                }
                width_c = -1;
                x--;
            } else {
                file.write(&bit_map[x], 1);
            }
            if (x == bit_map.size() - 1) {
                for (int i = rowSize - width / 2; i > 0; --i) {
                    char padding = 0;
                    file.write(&padding, 1);
                }
            }
        }
    }
}



