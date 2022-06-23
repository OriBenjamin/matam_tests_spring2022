#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

class Fighter : public Player 
{
    public:

    Fighter(const std::string name);
    Fighter(const Fighter& fighter) = delete;
    ~Fighter() = default;
    Fighter& operator=(const Fighter& fighter) = delete;
    int getAttackStrength() const override;

};

#endif //FIGHTER_H