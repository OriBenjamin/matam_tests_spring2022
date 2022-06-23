#include "Treasure.h"

using std::string;

const int TREASURE_OF_COINS = 10;
Treasure::Treasure():
Card("Treasure")
{}

void Treasure::cardEffect(Player& player)
{
    player.addCoins(TREASURE_OF_COINS);
    printTreasureMessage();
}