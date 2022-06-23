#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

 
class Treasure : public Card
{
    
    public:
    
    Treasure();
    Treasure(const Treasure& treasure) = delete;
    ~Treasure() = default;
    Treasure& operator=(const Treasure& treasure) = delete;
    void cardEffect(Player& player);

};



#endif //TREASURE_H