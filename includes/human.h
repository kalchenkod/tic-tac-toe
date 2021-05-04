#ifndef TIC_TAC_TOE_HUMAN_H
#define TIC_TAC_TOE_HUMAN_H

#include <algorithm>
#include "player.h"

class Human : public Player{
public:
    std::vector<int> peek(Playground &p) override  {
        std::vector<std::vector<int>> free_cells = p.get_free_cells();
        std::vector<int> position {-1, -1};
        int counter = 0;
        while (std::find(free_cells.begin(), free_cells.end(), position) == free_cells.end()) {
            std::cout << "--------------------" << std::endl;
            if (counter) {
                std::cerr << "Invalid input!" << std::endl;
                std::cerr << "(Type value between 0 and 2)" << std::endl << std::endl;
            }
            counter++;
            std::cout << "Choose row:";
            std::cin >> position[0];
            std::cout << "Choose column:";
            std::cin >> position[1];
            std::cout << "-----------------------" << std::endl;
        }
        return position;
    }
};


#endif //TIC_TAC_TOE_HUMAN_H
