#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"

 
class Fairy : public Card
{
    
    public:
    
    Fairy();
    Fairy(const Fairy& fairy) = delete;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& fairy) = delete;
    void cardEffect(Player& player);

};



#endif //FAIRY_H