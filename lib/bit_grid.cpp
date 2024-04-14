#include "bit_grid.h"


Grid::Grid() = default;

void Grid::addSand(int16_t x, int16_t y, uint64_t sand) {
    Cell* cell = getCell(x, y);
    if (cell) {
        cell->sand += sand;
    } else {
        cells.push_back({x, y, sand});
        if (x < minX) minX = x;
        if (y < minY) minY = y;
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }
}

Cell *Grid::getCell(int16_t x, int16_t y) {
    for (auto& cell : cells) {
        if (cell.x == x && cell.y == y) {
            return &cell;
        }
    }
    return nullptr;
}

int Grid::getValue(int16_t x, int16_t y) {
    for (auto& cell : cells) {
        if (cell.x == x && cell.y == y) {
            return cell.sand;
        }
    }
    return 0;
}

int Grid::distributeSand() {
    std::vector<Cell> toUpdate;
    bool flag_stability = true;
    for (auto& cell : cells) {
        if (cell.sand > 3) {
            flag_stability = false;
            cell.sand -= 4;
            toUpdate.push_back({static_cast<int16_t>(cell.x - 1), cell.y, 1});
            toUpdate.push_back({static_cast<int16_t>(cell.x + 1), cell.y, 1});
            toUpdate.push_back({cell.x, static_cast<int16_t>(cell.y - 1), 1});
            toUpdate.push_back({cell.x, static_cast<int16_t>(cell.y + 1), 1});
        }
    }
    for (const auto& cell : toUpdate) {
        addSand(cell.x, cell.y, cell.sand);
    }
    if (flag_stability) {
        return 1;
    } else {
        return 0;
    }
}

void Grid::fillGrid() {
    for (int16_t x = minX; x <= maxX; x++) {
        for (int16_t y = minY; y <= maxY; y++) {
            if (!getCell(x, y) or getCell(x, y)->sand == 0) {
                cells.push_back({x, y, 0});
            }
        }
    }
}
