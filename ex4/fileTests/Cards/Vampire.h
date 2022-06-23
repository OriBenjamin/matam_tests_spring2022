#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCards.h"


class Vampire : public BattleCard
{
    
    public:
    
    Vampire();
    Vampire(const Vampire& vampire) = delete;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& vampire) = delete;
    void cardEffect(Player& player);

};

#endif //VAMPIRE_H