#ifndef TIC_TAC_TOE_COMPUTER_RANDOM_H
#define TIC_TAC_TOE_COMPUTER_RANDOM_H

#include "player.h"

class Computer_random : public Player{
public:
    std::vector<int> peek(Playground &p) override {
        std::vector<std::vector<int>> free_cells = p.get_free_cells();
        return free_cells[rand() % free_cells.size()];
    }
};

#endif //TIC_TAC_TOE_COMPUTER_RANDOM_H
