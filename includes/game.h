#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H


class Game {
private:
    Player* player_1;
    Player* player_2;
    Playground ground;
public:
    Game(Player* &pl1, Player* &pl2) {
        player_1 = pl1;
        player_2 = pl2;
    }
    void play() {
        int turn = 1;
        while (!ground.is_full()) {
            ground.print();
            if (turn % 2) {
                std::cout << "First player turn" << std::endl;
                std::vector<int> choice = player_1->peek(ground);
                ground.set_cross(choice[0], choice[1]);
            }
            else {
                std::cout << "Second player turn" << std::endl;
                std::vector<int> choice = player_2->peek(ground);
                ground.set_circle(choice[0], choice[1]);
            }
            turn++;
            //_sleep(2000);
            if (ground.check_for_win() == 1) {
                ground.print();
                std::cout <<  std::endl;
                std::cout << "First player wins!" << std::endl;
                return;
            }
            else if (ground.check_for_win() == 2){
                ground.print();
                std::cout <<  std::endl;
                std::cout << "Second player wins!" << std::endl;
                return;
            }
        }
        ground.print();
        std::cout <<  std::endl;
        std::cout << "Draw! No one wins" << std::endl;
    };
};

#endif //TIC_TAC_TOE_GAME_H
