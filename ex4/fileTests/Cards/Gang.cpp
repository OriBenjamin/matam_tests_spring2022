#include "Gang.h"

using std::string;

Gang::Gang(const std::vector<string> namesOfCards):
Card("Gang")
{
    if(int(namesOfCards.size()) < 0)
    {
        throw GangSizeNotValid();
    }
    for(int i = 0; i < int(namesOfCards.size()); i++)
    {
        if(namesOfCards[i] == "Goblin")
        {
            m_battleCardsGang.push_back(new Goblin());
        }
        if(namesOfCards[i] == "Vampire")
        {
            m_battleCardsGang.push_back(new Vampire());
        }
        if(namesOfCards[i] == "Dragon")
        {
            m_battleCardsGang.push_back(new Dragon());
        }
    }
}

void Gang::cardEffect(Player& player)
{
    bool playerDefeatedGang = true;
    for(int i = 0; i<int(m_battleCardsGang.size()); i++)
    {
        if(player.getAttackStrength() >= m_battleCardsGang[i]->m_cardForce)
        {
            player.addCoins(m_battleCardsGang[i]->m_cardLoot);
        }
        else
        {
            playerDefeatedGang = false;
            for(int j = i; j<int(m_battleCardsGang.size()); j++)
            {
                if(m_battleCardsGang[j]->m_cardName == "Goblin")
                {
                    player.damage(m_battleCardsGang[j]->m_cardDamage);
                }
                else if(m_battleCardsGang[j]->m_cardName == "Vampire")
                {
                    player.damage(m_battleCardsGang[j]->m_cardDamage);
                    player.buff(-1);
                }
                else if(m_battleCardsGang[j]->m_cardName == "Dragon")
                {
                    player.damage(player.getPlayerHp());
                }
                printLossBattle(player.getPlayerName(), m_battleCardsGang[j]->m_cardName);
            }       
            break;
        }
    }
    if(playerDefeatedGang)
    {
        player.levelUp();
        printWinBattle(player.getPlayerName(), "Gang");
    }
}

void Gang::printCardData(std::ostream& os) const
{
    for(int i = 0; i<int(m_battleCardsGang.size()); i++)
    {
        printCardDetails(os, m_battleCardsGang[i]->m_cardName);
        if(m_battleCardsGang[i]->m_cardName == "Goblin" || m_battleCardsGang[i]->m_cardName == "Vampire" || m_battleCardsGang[i]->m_cardName == "Dragon")
        {
            if(m_battleCardsGang[i]->m_cardName.compare("Dragon")==0)
            {
                printMonsterDetails(os, m_battleCardsGang[i]->m_cardForce, m_battleCardsGang[i]->m_cardDamage, m_battleCardsGang[i]->m_cardLoot, true);
            }
            else
            {
                printMonsterDetails(os, m_battleCardsGang[i]->m_cardForce, m_battleCardsGang[i]->m_cardDamage, m_battleCardsGang[i]->m_cardLoot, false);
            }
        }
    }
}

    
Gang::~Gang()
{
    while(!m_battleCardsGang.empty())
    {
        delete m_battleCardsGang.back();
        m_battleCardsGang.pop_back();
    }
}