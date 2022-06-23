#include "Goblin.h"

using std::string;

Goblin::Goblin():
BattleCard("Goblin", 2, 6, 10)
{}
   
void Goblin::cardEffect(Player& player)
{
    if(player.getAttackStrength() >= this->m_cardForce)
    {
        try
        {
            player.levelUp(); 
            player.addCoins(this->m_cardLoot);
        }
        catch(PlayerHasAlreadyWon& exception)
        {
            throw PlayerHasAlreadyWon();
        }
        printWinBattle(player.getPlayerName(), this->m_cardName);
    }
    else
    {
        try
        {
            player.damage(this->m_cardDamage);
        }
        catch(InvalidArgument& exception)
        {
            throw InvalidArgument();
        }
        printLossBattle(player.getPlayerName(), this->m_cardName);
    }
}

