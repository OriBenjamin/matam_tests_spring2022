#include "Fairy.h"

using std::string;

const int HEAL_FROM_A_FAIRY = 10;
Fairy::Fairy():
Card("Fairy")
{}

void Fairy::cardEffect(Player& player)
{
    if(player.getPlayerJob() == "Wizard")
    {
        try
        {
            player.heal(HEAL_FROM_A_FAIRY);
            printFairyMessage(true);
        }
        catch(PlayerHasAlreadyWon& exception)
        {
            throw PlayerHasAlreadyWon();
        }
    }
    else
    {
        printFairyMessage(false);
    }
}