#ifndef ROGUE_H
#define ROGUE_H

#include "Player.h"


class Rogue : public Player 
{
    public:

    Rogue(const std::string name);
    Rogue(const Rogue& rogue) = delete;
    ~Rogue() = default;
    Rogue& operator=(const Rogue& rogue) = delete;
    void addCoins(const int coinsAmount) override;

};

#endif //ROGUE_H