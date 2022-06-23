#ifndef HealthPoints_H
#define HealthPoints_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int DEFAULT_MAX_HEALTH = 100;

class HealthPoints
{
    public:
    
    //constractur of HealthPoints
    HealthPoints(int maxHealthPoints = DEFAULT_MAX_HEALTH);

    //copy constractur of HealthPoints
    HealthPoints(const HealthPoints& healthPoints) = default;

    //destractur of HealthPoints
    ~HealthPoints() = default;

    int getCurrentHealthPoints() const;
    void setCurrentHealthPoints(int healthPoints);
    
    /*assignment operators:
        -the first perform assignment to HealthPoints object
         from an HealthPoints object
        -the second perform assignment to HealthPoints object from an integer
    */
    void operator=(const HealthPoints& healthPoints);
    void operator=(const int healthPointsValue);

    /*assignment operators- addition and subtraction:
        -add/subtract an integer value to/from m_currentHealthPoints field of
         HealthPoints object
    */
    HealthPoints& operator+=(const int healthPointsValue);
    HealthPoints& operator-=(const int healthPointsValue);

    class InvalidArgument {}; //an exception of HealthPoints class constractur
    

    private:

    int m_currentHealthPoints;
    int m_maxHealthPoints;

    /*comparison operator:
        -gets 2 HealthPoints objects and checks if one is "greater" than the other
        (based on their m_currentHealthPoints field) 
    */
    friend bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    
    /*printing operator:
        -prints the data of an HealthPoints object
    */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);

};

/*arithmetic operators- addition and subtraction:
    -get an HealthPoints object and integer value.
    -add/subtract the integer to/from HealthPoints m_currentHealthPoints field.
    -create a new obects and initialize him according to the result of
     the arithmetic operation
*/
HealthPoints operator+(const HealthPoints& healthPoints, const int healthPointsValue); //+ operator
HealthPoints operator+(const int healthPointsValue, const HealthPoints& healthPoints); //+ operator
HealthPoints operator-(const HealthPoints& healthPoints, const int healthPointsValue); //- operator

/*comparison operators:
    -compare between: two HealthPoints objects or an HealthPoints object
     and integer value.
    -check the following relations:
     greater than or equal to, equal to, not equal, less than, less than or equal to.	
*/
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //>= operator
bool operator>=(const HealthPoints& healthPoints1, const int healthPointsValue); //>= operator
bool operator>=(const int healthPointsValue, const HealthPoints& healthPoints1); //>= operator
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //== operator
bool operator==(const HealthPoints& healthPoints1, const int healthPointsValue); //== operator
bool operator==(const int healthPointsValue, const HealthPoints& healthPoints1); //== operator
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //!= operator
bool operator!=(const HealthPoints& healthPoints1, const int healthPointsValue); //!= operator
bool operator!=(const int healthPointsValue, const HealthPoints& healthPoints1); //!= operator
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //<= operator
bool operator<=(const HealthPoints& healthPoints1, const int healthPointsValue); //<= operator
bool operator<=(const int healthPointsValue, const HealthPoints& healthPoints1); //<= operator
bool operator>(const HealthPoints& healthPoints1, const int healthPointsValue); //> operator
bool operator>(const int healthPointsValue, const HealthPoints& healthPoints1); //> operator
bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //< operator
bool operator<(const HealthPoints& healthPoints1, const int healthPointsValue); //< operator
bool operator<(const int healthPointsValue, const HealthPoints& healthPoints1); //< operator

#endif //HealthPoints_H