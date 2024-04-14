#pragma once


struct Cell {

};

struct Grid {
    Grid() : minX(INT16_MAX), minY(INT16_MAX), maxX(INT16_MIN), maxY(INT16_MIN)

    void addSand(int16_t x, int16_t y, uint64_t sand)

    Cell* getCell(int16_t x, int16_t y)

    int getValue(int16_t x, int16_t y)

    void distributeSand()

    void fillGrid()
};

