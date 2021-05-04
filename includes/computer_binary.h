#ifndef TIC_TAC_TOE_COMPUTER_BINARY_H
#define TIC_TAC_TOE_COMPUTER_BINARY_H

#include "player.h"
#include "bTree.h"


class Computer_binary : public Player {
public:
    std::vector<int> peek(Playground &p) override {
        if (p.get_free_cells().size() == 1) {
            return p.get_free_cells()[0];
        }
        std::vector<int> choice;

        BTree tree(p);
        tree.build();
        BTree* left = tree.get_left();
        BTree* right = tree.get_right();

        Playground best_choice;
        if (p.get_free_cells().size() % 2) {
            if (left->count() > right->count()) {
                best_choice = left->get_playground();
            }
            else {
                best_choice = right->get_playground();
            }
        }
        else {
            if (left->count() > right->count()) {
                best_choice = right->get_playground();
            }
            else {
                best_choice = left->get_playground();
            }
        }

        return p.last_move(best_choice);
    }
};
#endif //TIC_TAC_TOE_COMPUTER_BINARY_H
