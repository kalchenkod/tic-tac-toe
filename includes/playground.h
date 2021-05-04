#ifndef TIC_TAC_TOE_PLAYGROUND_H
#define TIC_TAC_TOE_PLAYGROUND_H


class Playground {
private:
    std::vector<std::vector<int>> grid{3 ,std::vector<int>(3 ,0)};
    std::string cross = " X ";
    std::string circle = " O ";
    std::string empty = " _ ";
public:
    Playground()= default;;
    void set_cross(const int &x, const int &y) {
        if (get_cell(x, y)) {
            std::cerr << "Cell occupied" << std::endl;
            return;
        }
        grid[x][y] = 1;
    }

    void set_circle(const int &x, const int &y) {
        if (get_cell(x, y)) {
            std::cerr << "Cell occupied" << std::endl;
            return;
        }
        grid[x][y] = 4;
    }

    int get_cell(const int &x, const int &y) {
        if (x < 0 || x > 3 || y < 0 || y > 3) {
            std::cerr << "Index error" << std::endl;
            return -1;
        }
        return grid[x][y];
    }

    int check_for_win() {
        std::vector<int> winning_combinations;
        winning_combinations.push_back(grid[0][0] + grid[0][1] + grid[0][2]);
        winning_combinations.push_back(grid[1][0] + grid[1][1] + grid[1][2]);
        winning_combinations.push_back(grid[2][0] + grid[2][1] + grid[2][2]);
        winning_combinations.push_back(grid[0][0] + grid[1][0] + grid[2][0]);
        winning_combinations.push_back(grid[0][1] + grid[1][1] + grid[2][1]);
        winning_combinations.push_back(grid[0][2] + grid[1][2] + grid[2][2]);
        winning_combinations.push_back(grid[0][0] + grid[1][1] + grid[2][2]);
        winning_combinations.push_back(grid[0][2] + grid[1][1] + grid[2][0]);
        for (const auto &comb: winning_combinations) {
            if (comb == 3) {
                return 1;
            }
            else if (comb == 12) {
                return 2;
            }
        }
        return 0;
    }

    std::vector<std::vector<int>> get_free_cells() {
        std::vector<std::vector<int>> free_cells;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!grid[i][j]) {
                    std::vector<int> cell {i, j};
                    free_cells.push_back(cell);
                }
            }
        }
        return free_cells;
    }

    bool is_full() {
        return get_free_cells().empty();
    }

    void print() {
        std::cout << "--------------------" << std::endl;
        for (const auto &i : grid) {
            for (const auto &j : i) {
                std::cout << " | ";
                if (j == 1) {
                    std::cout << cross;
                }
                else if (j == 4) {
                    std::cout << circle;
                }
                else {
                    std::cout << empty;
                }
            }
            std::cout << " | " << std::endl;
        }
        std::cout << "--------------------" << std::endl;
    }

    std::vector<int> last_move(Playground &new_ground) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != new_ground.get_cell(i, j)) {
                    std::vector<int> choice {i, j};
                    return choice;
                }
            }
        }
    }

    Playground(Playground &copied)
    {
        grid = copied.grid;
    }
};


#endif //TIC_TAC_TOE_PLAYGROUND_H
