#ifndef GANG_H
#define GANG_H

#include "BattleCards.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "../Exception.h"
#include "../utilities.h"
#include <iostream>
#include <vector>




class Gang : public Card
{
    
    public:
    
    Gang(const std::vector<std::string> namesOfCards);
    Gang(const Gang& gang) = delete;
    ~Gang();
    Gang& operator=(const Gang& gang) = delete;
    void cardEffect(Player& player);
    void printCardData(std::ostream& os) const override;
    
    private:
    std::vector<BattleCard*> m_battleCardsGang;

    
};

#endif //GANG_H