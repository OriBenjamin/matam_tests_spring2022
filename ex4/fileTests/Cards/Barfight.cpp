#include "Barfight.h"

using std::string;

const int DAMAGE_AT_BAR_FIGHT = 10;

Barfight::Barfight():
Card("Barfight")
{}

void Barfight::cardEffect(Player& player)
{
    if(player.getPlayerJob() != "Fighter")
    {
        player.damage(DAMAGE_AT_BAR_FIGHT);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}