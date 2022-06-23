#include "Vampire.h"

using std::string;

Vampire::Vampire():
BattleCard("Vampire", 2, 10, 10)
{}
   
void Vampire::cardEffect(Player& player)
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
            player.buff(-1);
        }
        catch(InvalidArgument& exception)
        {
            throw InvalidArgument();
        }
        printLossBattle(player.getPlayerName(), this->m_cardName);

    }
}

