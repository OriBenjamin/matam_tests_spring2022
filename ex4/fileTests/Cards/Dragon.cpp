#include "Dragon.h"

using std::string;
using std::ostream;

const int INFINITY = 0; //the value of infinity does not important except for its meaning
Dragon::Dragon():
BattleCard("Dragon", 1000, 25, INFINITY)
{}



void Dragon::cardEffect(Player& player)
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
            player.damage(player.getPlayerHp());
            printLossBattle(player.getPlayerName(), this->m_cardName);
        }
        catch(InvalidArgument& exception)
        {
            throw InvalidArgument();
        }
    }
}