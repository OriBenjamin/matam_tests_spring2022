#ifndef BattleCards_H
#define BattleCards_H

#include <string>
#include "Card.h"
#include "../utilities.h"


class BattleCard : public Card
{
    
    public:
    
    BattleCard(const std::string name, const int cardLoot, const int cardForce, const int cardDamage);
    BattleCard(const BattleCard& battleCard) = delete;
    virtual ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& battleCard) = delete;
    void printCardData(std::ostream& os) const override;
    virtual void cardEffect(Player& player) = 0;
    friend class Gang;

    protected:

    const int m_cardLoot;
    const int m_cardForce;
    const int m_cardDamage;
};

#endif //BattleCards_H
