#include "Fighter.h"

using std::string;

Fighter::Fighter(const string name):
Player(name, "Fighter")
{}

int Fighter::getAttackStrength() const
{
    return this->m_playerForce*2 + this->m_playerLevel;
}