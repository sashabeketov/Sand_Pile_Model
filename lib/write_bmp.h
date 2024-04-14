#pragma once
#include "bit_grid.h"
#include <iostream>
#include <fstream>

void WriteBMP(const std::string& path_name, const std::string& bmp_file_name, std::vector<char>& bit_map, uint32_t width, uint32_t height);
