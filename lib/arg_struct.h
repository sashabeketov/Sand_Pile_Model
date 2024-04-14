#pragma once
#include <string>

struct ARGS{
public:
    std::string csv_name_;
    std::string path_name_;
    int iteration_;
    int freq_;

    ARGS();

    void addARGS(const std::string& csv_name, const std::string& path_name, int iteration, int freq);
};
