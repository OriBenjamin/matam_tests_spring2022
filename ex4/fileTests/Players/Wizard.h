#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"


class Wizard : public Player 
{
    public:

    Wizard(const std::string name);
    Wizard(const Wizard& wizard) = delete;
    ~Wizard() = default;
    Wizard& operator=(const Wizard& wizard) = delete;
    void heal(const int healAmount) override;

};

#endif //WIZARD_H