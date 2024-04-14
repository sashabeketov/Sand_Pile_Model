#include "BMP_struct.h"
#include "my_vector.h"
#include "write_bmp.h"
#include "fstream"

void WriteBMP(const std::string& path_name, const std::string& bmp_file_name, TwoDimVector &bit_map, int width, int height) {
    int additional;
    if (width % 2 == 0) {
         additional = ((4 - (width / 2) % 4) % 4);
     } else {
        additional = ((4 - (width / 2) % 4) % 4) - 1;
    }

    const int fileHeaderSize = 14;
    const int informationalHeaderSize = 40;
    const int fileSize = fileHeaderSize + informationalHeaderSize + (width / 2 + width % 2) * height + additional * height;

    std::ofstream path(path_name);
    if (!path.is_open()) {
        std::cerr << "Failed to create directory " << path_name;
    }
    path.close();

    std::ofstream bmp_file;
    bmp_file.open(path_name + bmp_file_name, std::ios::binary);
    if (!bmp_file.is_open()) {
        std::cerr << "File could not be opened";
    }

    for (int i = bit_map.get_col() - 1; i >= 0; --i) {
        for (int j)
    }
}
