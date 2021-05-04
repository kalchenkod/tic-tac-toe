#ifndef TIC_TAC_TOE_BTREE_H
#define TIC_TAC_TOE_BTREE_H

#include <cmath>

class BTree {
private:
    Playground p;
    BTree* left;
    BTree* right;
public:
    BTree(Playground &rootObj) {
        p = rootObj;
        left = nullptr;
        right = nullptr;
    }

    void insert_left() {
        Playground new_p = p;
        std::vector<std::vector<int>> free_cells = new_p.get_free_cells();
        std::vector<int> choice =  free_cells[rand() % free_cells.size()];
        if (p.get_free_cells().size() % 2) {
            new_p.set_cross(choice[0], choice[1]);
        }
        else {
            new_p.set_circle(choice[0], choice[1]);
        }
        left = new BTree(new_p);
    }

    void insert_right() {
        Playground new_p = p;
        std::vector<std::vector<int>> free_cells = new_p.get_free_cells();
        std::vector<int> choice =  free_cells[rand() % free_cells.size()];
        if (p.get_free_cells().size() % 2) {
            new_p.set_cross(choice[0], choice[1]);
        }
        else {
            new_p.set_circle(choice[0], choice[1]);
        }
        right = new BTree(new_p);
    }

    void build() {
        if (p.is_full() || p.check_for_win()) {
            return;
        }
        insert_left();
        insert_right();
        BTree* l = get_left();
        BTree* r = get_right();
        l->build();
        r->build();
    }

    int count() {
        if (p.check_for_win() == 1) {
            int free = p.get_free_cells().size();
            return pow(2,free);
        }
        else if (p.check_for_win() == 2) {
            int free = p.get_free_cells().size();
            return -1*pow(2,free);
        }
        else if (p.is_full() || left == nullptr) {
            return 0;
        }
        else {
            return left->count() + right->count();
        }
    }

    BTree* get_left() {
        return left;
    }

    BTree* get_right() {
        return right;
    }

    Playground get_playground() {
        return p;
    }
};

#endif //TIC_TAC_TOE_BTREE_H
