#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "HealthPoints.h"
#include "../Exception.h"

const int Current_Amount_Of_Player_Types = 3;

class Player 
{
    public:

    Player(const std::string name, const std::string job);
    Player(const Player& player) = delete;
    virtual ~Player() = default;
    Player& operator=(const Player& player) = delete;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    void levelUp();
    void buff(const int buffAmount);
    virtual void heal(const int healAmount);
    void damage(const int damageAmount);
    bool isKnockedOut() const;
    virtual void addCoins(const int coinsAmount);
    void pay(const int payAmount);
    virtual int getAttackStrength() const;
    friend class HealthPoints;
    friend class Card;
    const std::string getPlayerJob() const;
    const std::string getPlayerName() const;
    const int getPlayerCoins() const;
    int getPlayerHp() const;
    bool playerHasWon();


    protected:

    const std::string m_playerName;
    const std::string m_playerJob;
    HealthPoints m_playerHp;
    int m_playerLevel;
    int m_playerCoins;
    int m_playerForce;

};

const std::string playerJobTypes[3] = {"Rogue", "Wizard", "Fighter"};
bool playerNameIsValid(const std::string name);

bool playerClassIsValid(const std::string name, const std::string playerJobTypes[] = playerJobTypes, 
const int currentAmountOfPlayerTypes = Current_Amount_Of_Player_Types);


#endif //PLAYER_H