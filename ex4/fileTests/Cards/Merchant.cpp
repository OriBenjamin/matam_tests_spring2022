#include "Merchant.h"
#include <iostream>
#include <bitset>
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::stoi;

const int BUY_NOTHING = 0;
const int BUY_ONE_HEALTHPOINT = 1;
const int BUY_ONE_FORCE_UNIT = 2;

const int ONE_HEALTHPOINT_PRICE = 5;
const int ONE_FORCE_UNIT_PRICE = 10;

Merchant::Merchant():
Card("Merchant")
{}

void Merchant::cardEffect(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getPlayerName(), player.getPlayerCoins());
    string userInput;
    int integerInput = -1;
    do
    {
        try
        {
            do
            {
                getline(cin, userInput);
            } while(userInput.empty());
            if(userInput == "0")
            {
                integerInput = 0;
            }
            else if(userInput == "1")
            {
                integerInput = 1;
            }
            else if(userInput == "2")
            {
                integerInput = 2;
            }
            else
            {
                //std::cout << "input is:" << userInput << "okk" << std::endl;
                printInvalidInput();
                continue;
            }
        } 
        catch(const std::invalid_argument& exception)
        {
            //std::cout << "input is:" << userInput << "okk" << std::endl;
            printInvalidInput();
            continue;
        }
        // catch(const std::out_of_range& exception)
        // {
        //     printInvalidInput();
        //     continue;
        // }
    } while(integerInput != BUY_NOTHING && integerInput != BUY_ONE_HEALTHPOINT && integerInput != BUY_ONE_FORCE_UNIT);
   // cout << "the input is:" << userInput << "ok." << std::endl;
   /* do
    {
        cin >> userInput;
        if(cin.fail()|| (userInput != BUY_NOTHING && userInput != BUY_ONE_HEALTHPOINT && userInput != BUY_ONE_FORCE_UNIT))
        {
            printInvalidInput();
            cin.clear();
            continue;
        }
    } while (false);     */

    switch(integerInput)
    {
        case BUY_NOTHING:
            printMerchantSummary(cout, player.getPlayerName(), BUY_NOTHING, 0);
            break;
        case BUY_ONE_HEALTHPOINT:
            if(player.getPlayerCoins() < ONE_HEALTHPOINT_PRICE)
            {
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_HEALTHPOINT, 0);
            }
            else
            {
                player.pay(ONE_HEALTHPOINT_PRICE);
                player.heal(1);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_HEALTHPOINT, ONE_HEALTHPOINT_PRICE);
            }
            break;
        case BUY_ONE_FORCE_UNIT:
            if(player.getPlayerCoins() < ONE_FORCE_UNIT_PRICE)
            {
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_FORCE_UNIT, 0);
            }
            else
            {
                player.pay(ONE_FORCE_UNIT_PRICE);
                player.buff(1);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_FORCE_UNIT, ONE_FORCE_UNIT_PRICE);
            }
            break;
    }
}
