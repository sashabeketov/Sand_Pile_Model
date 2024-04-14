#include "arg_struct.h"

ARGS::ARGS() = default;

void ARGS::addARGS(const std::string &csv_name, const std::string &path_name, int iteration, int freq) {
    csv_name_ = csv_name;
    path_name_ = csv_name;
    iteration_ = iteration;
    freq_ = freq;
}




