#include "Mtmchkin.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::cin;

Mtmchkin::Mtmchkin(const string fileName):
m_teamSize(0),
m_roundsCount(0)
{
    printStartGameMessage();
    ifstream cardsFile(fileName, std::ifstream::in);
    if(!cardsFile.is_open())
    {
        throw DeckFileNotFound();
    }
    try
    {
        this->recieveCards(cardsFile);
    } catch (const DeckFileFormatError& exception)
    {
        throw exception;
    }
    cardsFile.close();

    printEnterTeamSizeMessage();
    do
    {
        // cin >> m_teamSize;
        // if(cin.fail() || m_teamSize < 2 || m_teamSize > 6)
        // {
        //     std::cout << "not normal: " << m_teamSize << std::endl;
        //     printInvalidTeamSize();
        //     printEnterTeamSizeMessage();
        //     cin.clear();
        //     continue;
        // }
        // std::cout << "normal: " << m_teamSize << std::endl;
        // break;

        string stringTeamSize;
        try
        {
            getline(cin, stringTeamSize);
            if(stringTeamSize == "2")
            {
                m_teamSize = 2;
            } else if(stringTeamSize == "3")
            {
                m_teamSize = 3;
            } else if(stringTeamSize == "4")
            {
                m_teamSize = 4;
            } else if(stringTeamSize == "5")
            {
                m_teamSize = 5;
            } else if(stringTeamSize == "6")
            {
                m_teamSize = 6;
            } else
            {
                printInvalidTeamSize();
                printEnterTeamSizeMessage();
                continue;
            }
        } 
        catch(const std::invalid_argument& exception)
        {
            //std::cout << "input is:" << userInput << "okk" << std::endl;
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        break;
    } while (true);
    
    this->recievePlayers();
}

void Mtmchkin::recieveCards(ifstream& cardsFile)
{    
    string cardName;
    int lineNumber = 0;
    bool gangIsValid = false;
    std::vector<string> namesOfCards;
    while(std::getline(cardsFile, cardName))
    {
        lineNumber++;
        if(cardName == "Gang")
        {
            while(std::getline(cardsFile, cardName))
            {
                lineNumber++;
                if(cardName == "Goblin" || cardName == "Vampire" || cardName == "Dragon")
                {
                    namesOfCards.push_back(cardName);
                }
                else if(cardName == "EndGang")
                {
                    gangIsValid = true;
                    break;
                }
                else
                {
                    throw DeckFileFormatError(lineNumber);
                }
            }
            if(!gangIsValid)
            {
                throw DeckFileFormatError(lineNumber + 1);
            }
            m_cards.push(new Gang(namesOfCards));
        }
        else if(!pushCards(m_cards, cardName))
        {
            throw DeckFileFormatError(lineNumber);
        }
        
    }
    if(lineNumber < 5)
    {
        throw DeckFileInvalidSize();
    }
}

void Mtmchkin::recievePlayers()
{
    string playerName;
    string playerKind;
    for(int i=0; i < m_teamSize; i++)
    {
        printInsertPlayerMessage();
        do
        {
            cin >> playerName;
            cin >> playerKind;
            if(!playerNameIsValid(playerName))
            {
                printInvalidName();
                continue;
            }
            if(playerKind == "Rogue")
            {
                m_players.push(new Rogue(playerName));
            }
            else if(playerKind == "Wizard")
            {
                m_players.push(new Wizard(playerName));
            }
            else if(playerKind == "Fighter")
            {
                m_players.push(new Fighter(playerName));
            }
            else
            {
                printInvalidClass();
                continue;
            }    
            break;
        } while(true);
    }
}

bool pushCards(std::queue<Card*>& cards, const string cardName)
{
        if(cardName == "Goblin")
        {
            cards.push(new Goblin());
        }
        else if(cardName == "Dragon")
        {
            cards.push(new Dragon());
        }
        else if(cardName == "Fairy")
        {
            cards.push(new Fairy());
        }        
        else if(cardName == "Merchant")
        {
            cards.push(new Merchant());
        }   
        else if(cardName == "Pitfall")
        {
            cards.push(new Pitfall());
        }
        else if(cardName == "Treasure")
        {
            cards.push(new Treasure());
        }
        else if(cardName == "Vampire")
        {
            cards.push(new Vampire());
        }   
        else if(cardName == "Barfight")
        {
            cards.push(new Barfight());
        }
        else
        {
            return false;
        }
    return true;
}

void Mtmchkin::playRound()
{
    m_roundsCount++;
    printRoundStartMessage(m_roundsCount);
    for(int i=0; i < m_teamSize; i++)
    {
        printTurnStartMessage(m_players.front()->getPlayerName());
        m_cards.front()->cardEffect(*(m_players.front()));
        if(m_players.front()->isKnockedOut())
        {
            m_losers.push_back(m_players.front());
            m_players.front() = NULL; //prevent destruction of player
            m_players.pop();
        }
        else if(m_players.front()->playerHasWon())
        {
            m_winners.push_back(m_players.front());
            m_players.front() = NULL;
            m_players.pop();
        }
        else
        {
            m_players.push(m_players.front());
            m_players.front() = NULL;
            m_players.pop();
        }
        m_cards.push(m_cards.front());
        m_cards.front() = NULL; //prevent destruction of card
        m_cards.pop();
    }
    m_teamSize = m_players.size();
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int currentRank = 1;
    for(int i = 0; i < int(m_winners.size()); i++) ////forwards interation
    {
        printPlayerLeaderBoard(currentRank, *m_winners[i]);
        currentRank++;
    }

    std::queue<Player*> playersCopy = m_players;
    while (!playersCopy.empty())
    {
        printPlayerLeaderBoard(currentRank, *playersCopy.front());
        playersCopy.pop();
        currentRank++;
    }
 
    for(int i = m_losers.size()-1; i >= 0; i--) //backwards interation
    {
        printPlayerLeaderBoard(currentRank, *m_losers[i]);
        currentRank++;
    }
}
    

bool Mtmchkin::isGameOver() const
{
    return m_players.size() == 0;
}
    

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsCount;
}



Mtmchkin::~Mtmchkin()
{
    while(!m_winners.empty())
    {
        delete m_winners.back();
        m_winners.pop_back();
    }
    
    while(!m_losers.empty())
    {
        delete m_losers.back();
        m_losers.pop_back();
    }

    while(!m_cards.empty())
    {
        delete m_cards.front();
        m_cards.pop();
    }

    while(!m_players.empty())
    {
        delete m_players.front();
        m_players.pop();
    }
}