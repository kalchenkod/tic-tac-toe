#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

class Player {
public:
    virtual std::vector<int> peek(Playground &p) = 0;
};

#endif //TIC_TAC_TOE_PLAYER_H
