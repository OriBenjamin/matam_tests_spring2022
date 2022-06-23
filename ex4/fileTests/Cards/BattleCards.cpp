#include "BattleCards.h"
#include <iostream>
using std::string;
using std::ostream;


BattleCard::BattleCard(const string name, const int cardLoot, const int cardForce, const int cardDamage):
Card(name),
m_cardLoot(cardLoot),
m_cardForce(cardForce),
m_cardDamage(cardDamage)
{}

void BattleCard::printCardData(std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    if(this->m_cardName == "Goblin" || this->m_cardName == "Vampire" || this->m_cardName == "Dragon")
    {
        if(this->m_cardName.compare("Dragon")==0)
        {
            printMonsterDetails(os, this->m_cardForce, this->m_cardDamage, this->m_cardLoot, true);
        }
        else
        {
            printMonsterDetails(os, this->m_cardForce, this->m_cardDamage, this->m_cardLoot, false);
        }
    }
}

