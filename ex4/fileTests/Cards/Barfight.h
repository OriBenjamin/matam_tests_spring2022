#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

 
class Barfight : public Card
{
    
    public:
    
    Barfight();
    Barfight(const Barfight& barfight) = delete;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& barfight) = delete;
    void cardEffect(Player& player);

};



#endif //BARFIGHT_H