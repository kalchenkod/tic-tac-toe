#include <iostream>
#include <vector>
#include <map>
#include "includes/playground.h"
#include "includes/computer_random.h"
#include "includes/computer_binary.h"
#include "includes/human.h"
#include "includes/game.h"


int main() {
    std::cout << "Start tic-tac-toe game!" << std::endl;
    std::cout << "Choose the players" << std::endl;
    std::cout << "(h - human, cr - computer using random, cb -- computer, using binary tree.)" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::vector<std::string> options{"h", "cr", "cb"};
    std::vector<std::string> choice{"--", "--"};
    int counter = 0;
    while (std::find(options.begin(), options.end(), choice[0]) == options.end()) {
        if (counter) {
            std::cerr << "Invalid input!" << std::endl;
        }
        counter++;
        std::cout << "First player:";
        std::cin >> choice[0];
        std::cout << "--------------------" << std::endl;
    }
    counter = 0;
    while (std::find(options.begin(), options.end(), choice[1]) == options.end()) {
        if (counter) {
            std::cerr << "Invalid input!" << std::endl;
        }
        counter++;
        std::cout << "Second player:";
        std::cin >> choice[1];
        std::cout << "--------------------" << std::endl;
    }
    std::cout << "The game starts!" << std::endl;
    std::vector<Player *> players;
    for (const auto &x : choice) {
        if (x == "h") {
            Human h;
            players.push_back(&h);
        }
        else if (x == "cr") {
            Computer_random cr;
            players.push_back(&cr);
        }
        else {
            Computer_binary cb;
            players.push_back(&cb);
        }
    }
    Game game(players[0], players[1]);
    game.play();

    return 0;
}
