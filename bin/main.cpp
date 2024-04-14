#include "arg_struct.h"
#include "arg_parser.h"
#include "bit_grid.h"
#include "write_bmp.h"

const uint8_t CSV_FILE_ERR = 1;

int main(int argc, char* argv[]){
    ARGS args = ParsArgs(argc, argv);

    args.path_name_ += "/";

    std::ifstream csv_file(args.csv_name_);

    if (!csv_file.is_open()) {
        std::cerr << "csv-file could not be open.\nPlease use '-h' or '--help' flag to se documentation";
        return CSV_FILE_ERR;
    }

    Grid grid;

    while (csv_file) {
        int16_t x_f;
        int16_t y_f;
        int grains;
        csv_file >> x_f;
        csv_file >> y_f;
        csv_file >> grains;
        grid.addSand(x_f, y_f, grains);
    }
    int freq_f = 0;
    int freq_file = 0;

    for (int i = 0; i < args.iteration_; i++) {
        freq_f++;

        std::vector<char> byte_data;


        int controller = 0;


        std::string file_name = "freq_";

        unsigned char tmp_byte = 0;

        char F = 0b1111;
        char A = 0b0010;
        char E = 0b1110;
        char D = 0b1101;
        char _0_ = 0b0000;


        if (grid.distributeSand() == 1) {
            grid.fillGrid();
            for (int16_t y = grid.minY; y <= grid.maxY; y++) {
                for (int16_t x = grid.minX; x <= grid.maxX; x++) {
                    controller++;
                    if (controller == 1) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = _0_ << 4;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = F << 4;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = A << 4;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = E << 4;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = D << 4;
                        }
                        if (x == grid.maxX) {
                            tmp_byte = tmp_byte | _0_;
                            byte_data.push_back(tmp_byte);
                        }
                    } else if (controller == 2) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = tmp_byte | _0_;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = tmp_byte | F;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = tmp_byte | A;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = tmp_byte | E;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = tmp_byte | D;
                        }
                        byte_data.push_back(tmp_byte);
                        tmp_byte = 0;
                        controller = 0;
                    }
                }
            }
            uint32_t height_image = grid.maxY - grid.minY + 1;
            uint32_t width_image = grid.maxX - grid.minX + 1;
            WriteBMP(args.path_name_, "final_result_stability.bmp", byte_data, width_image, height_image);

        }
        grid.fillGrid();

        uint32_t height_image = grid.maxY - grid.minY + 1;
        uint32_t width_image = grid.maxX - grid.minX + 1;

        if (freq_f % args.freq_ == 0 && args.freq_ != 0) {
            for (int16_t y = grid.minY; y <= grid.maxY; y++) {
                for (int16_t x = grid.minX; x <= grid.maxX; x++) {
                    controller++;
                    if (controller == 1) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = _0_ << 4;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = F << 4;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = A << 4;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = E << 4;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = D << 4;
                        }
                        if (x == grid.maxX) {
                            tmp_byte = tmp_byte | _0_;
                            byte_data.push_back(tmp_byte);
                            tmp_byte = 0;
                            controller--;
                        }
                    } else if (controller == 2) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = tmp_byte | _0_;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = tmp_byte | F;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = tmp_byte | A;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = tmp_byte | E;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = tmp_byte | D;
                        }
                        byte_data.push_back(tmp_byte);
                        tmp_byte = 0;
                        controller = 0;
                    }
                }
            }
            freq_file++;
            WriteBMP(args.path_name_, file_name + std::to_string(freq_file) + ".bmp", byte_data, width_image, height_image);
        } else if (args.freq_ == 0 && i == args.iteration_ - 1) {
            for (int16_t y = grid.minY; y <= grid.maxY; y++) {
                for (int16_t x = grid.minX; x <= grid.maxX; x++) {
                    controller++;
                    if (controller == 1) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = _0_ << 4;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = F << 4;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = A << 4;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = E << 4;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = D << 4;
                        }
                        if (x == grid.maxX) {
                            tmp_byte = tmp_byte | _0_;
                            byte_data.push_back(tmp_byte);
                        }
                    } else if (controller == 2) {
                        if (grid.getValue(x, y) > 3) {
                            tmp_byte = tmp_byte | _0_;
                        } else if (grid.getValue(x, y) == 0) {
                            tmp_byte = tmp_byte | F;
                        } else if (grid.getValue(x, y) == 1) {
                            tmp_byte = tmp_byte | A;
                        } else if (grid.getValue(x, y) == 2) {
                            tmp_byte = tmp_byte | E;
                        } else if (grid.getValue(x, y) == 3) {
                            tmp_byte = tmp_byte | D;
                        }
                        byte_data.push_back(tmp_byte);
                        tmp_byte = 0;
                        controller = 0;
                    }
                }
            }
            WriteBMP(args.path_name_, "final_result", byte_data, width_image, height_image);
        }
    }
    return 0;
}





