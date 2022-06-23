#ifndef GOBLIN_H
#define GOBLIN_H

#include "BattleCards.h"


class Goblin : public BattleCard
{
    
    public:
    
    Goblin();
    Goblin(const Goblin& goblin) = delete;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& goblin) = delete;
    void cardEffect(Player& player);

};

#endif //GOBLIN_H

