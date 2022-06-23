#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"


 
class Merchant : public Card
{
    
    public:
    
    Merchant();
    Merchant(const Merchant& merchant) = delete;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& merchant) = delete;
    void cardEffect(Player& player);

};


#endif //MERCHANT_H