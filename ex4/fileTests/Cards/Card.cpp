#include "Card.h"

using std::string;

//Card constructor- update Cards fields according to the given parameters
Card::Card(const string name):
m_cardName(name)
{
    if(!cardNameIsValid(name))
    {
        throw InvalidCardName();
    }
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printCardData(os);
    printEndOfCardDetails(os);
    return os;
}

void Card::printCardData(std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
}
bool cardNameIsValid(const string name, const string cardTypes[], const int currentAmountOfCardTypes)
{
    for(int i = 0; i < currentAmountOfCardTypes; i++)
    {
        if(name.compare(cardTypes[i])==0)
        {
            return true;
        }
    }
    return false;
}
