#ifndef Exception_H
#define Exception_H
#include <iostream>
#include <cstring>
#include <sstream>
#include <functional>
#include <exception>

class DeckException : public std::runtime_error 
{
    public:
    DeckException(const std::string& what):
    std::runtime_error(what)
    {}
}; 
class InvalidCardName
{};
class PlayerHasAlreadyWon{};
class InvalidArgument{};
class PlayerHasNotEnughCoins{};
class InvalidPlayerName{};
class InvalidPlayerClass{};
class GangSizeNotValid{};

class DeckFileFormatError : public DeckException
{
    private:
    const int m_lineNumber;
    public:
    DeckFileFormatError(int lineNumber):
    DeckException(std::string("Deck File Error: File format error in line ") + std::to_string(lineNumber)),
    m_lineNumber(lineNumber)
    {}
};
class DeckFileNotFound : public DeckException
{
    public:
    DeckFileNotFound():
    DeckException(std::string("Deck File Error: File not found"))
    {}
};
class DeckFileInvalidSize : public DeckException
{
    public:
    DeckFileInvalidSize():
    DeckException(std::string("Deck File Error: Deck size is invalid"))
    {}
};


#endif //Exception_H
