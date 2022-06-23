#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Gang.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"
#include "utilities.h"
#include <iostream>
#include <queue>
#include <vector>


class Mtmchkin
{

    public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    ~Mtmchkin();
    private:
    std::queue<Card*> m_cards;
    std::queue<Player*> m_players;
    std::vector<Player*> m_winners;
    std::vector<Player*> m_losers;
    int m_teamSize;
    int m_roundsCount;

    void recieveCards(std::ifstream& cardsFile);
    void recievePlayers();

};
//a function that pushes the right cards to the deck, returning true if worked.
bool pushCards(std::queue<Card*>& cards, const std::string cardName);

#endif /* MTMCHKIN_H_ */
