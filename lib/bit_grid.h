#pragma once
#include "vector"

struct Cell {
    int16_t x;
    int16_t y;
    uint64_t sand;
};

struct Grid {
    std::vector<Cell> cells;
    int16_t minX = INT16_MAX, minY = INT16_MAX;
    int16_t maxX = INT16_MIN, maxY = INT16_MIN;

    Grid();

    void addSand(int16_t x, int16_t y, uint64_t sand);

    Cell* getCell(int16_t x, int16_t y);

    int getValue(int16_t x, int16_t y);

    int distributeSand();

    void fillGrid();
};

