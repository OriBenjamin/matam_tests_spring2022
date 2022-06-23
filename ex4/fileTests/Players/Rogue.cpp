#include "Rogue.h"

using std::string;

Rogue::Rogue(const string name):
Player(name, "Rogue")
{}

void Rogue::addCoins(const int coinsAmount)
{
    if(coinsAmount <= 0)
    {
        throw InvalidArgument();
    }
    else
    {
        this->m_playerCoins += 2*coinsAmount; 
    }
}
