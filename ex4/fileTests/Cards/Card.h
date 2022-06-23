#ifndef Card_H
#define Card_H

#include <string>
#include "../Exception.h"
#include "../Players/Player.h"
#include "../utilities.h"

const std::string cardTypes[9] = {"Goblin", "Vampire", "Dragon", "Merchant", "Treasure", "Pitfall", "Barfight", "Fairy", "Gang"};
const int CURRENT_AMOUNT_OF_CARD_TYPES = 9;

class Card
{
    
    public:
    
    Card(const std::string name);
    Card(const Card& card) = delete;
    virtual ~Card() = default;
    Card& operator=(const Card& card) = delete;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual void printCardData(std::ostream& os) const;
    virtual void cardEffect(Player& player) = 0;

    protected:
    std::string m_cardName;
};

bool cardNameIsValid(const std::string name, const std::string cardTypes[] = cardTypes, const int currentAmountOfCardTypes = CURRENT_AMOUNT_OF_CARD_TYPES);



#endif //Card_H
