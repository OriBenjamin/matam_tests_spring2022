#include "Pitfall.h"

using std::string;

const int DAMAGE_FROM_FALLING_INTO_A_PIT = 10;
Pitfall::Pitfall():
Card("Pitfall")
{}

void Pitfall::cardEffect(Player& player)
{
    if(player.getPlayerJob() != "Rogue")
    {
        
        player.damage(DAMAGE_FROM_FALLING_INTO_A_PIT);
        printPitfallMessage(false);
        
    }
    else
    {
        printPitfallMessage(true);

    }
}