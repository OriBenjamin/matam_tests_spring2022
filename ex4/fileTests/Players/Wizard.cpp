#include "Wizard.h"

using std::string;

Wizard::Wizard(const string name):
Player(name, "Wizard")
{}

void Wizard::heal(const int healAmount)
{
    if(healAmount <= 0)
    {
        throw InvalidArgument();
        
    }
    else
    {
        this->m_playerHp += 2*healAmount;
    }
}