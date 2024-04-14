#include "arg_parser.h"
#include "iostream"

ARGS ParsArgs(int &argc, char *argv[]) {
    ARGS args;
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-i") == 0 ||
            std::strcmp(argv[i], "--input") == 0){
            args.csv_name_ = argv[++i];
        }
        if (std::strcmp(argv[i], "-o") == 0 ||
            std::strcmp(argv[i], "--output") == 0) {
            args.path_name_ = argv[++i];
        }
        if (std::strcmp(argv[i], "-m") == 0 ||
            std::strcmp(argv[i], "--max-iter") == 0) {
            args.iteration_ = std::stoi(argv[++i]);
        }
        if (std::strcmp(argv[i], "-f") == 0 ||
            std::strcmp(argv[i], "--freq") == 0) {
            args.freq_ = std::stoi(argv[++i]);
        }
        if (std::strcmp(argv[i], "-h") == 0 ||
            std::strcmp(argv[i], "--help") == 0){
            std::cout << "Usage: program_name [options]\n"
                      << "Options:\n"
                      << "  -h, --help\t\tShow this help message and exit\n"
                      << "  -i, --input\t\tSpecify the TSV (tab-separated values) file with initial data\n"
                      << "  -o, --output\t\tSpecify the directory path to save images\n"
                      << "  -m, --max-iter\tSpecify the maximum number of model iterations\n"
                      << "  -f, --freq\t\tSpecify the frequency at which images should be saved (if 0, only the final state is saved)\n";

        }
    }
    return args;
}
