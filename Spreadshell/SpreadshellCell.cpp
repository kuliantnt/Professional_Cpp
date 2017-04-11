#include "SpreadshellCell.h"
#include <iostream>
#include <sstream>

/************************************************************************/
/* ¹¹Ôìº¯Êý                                                              */
/************************************************************************/


SpreadshellCell & SpreadshellCell::operator=(const SpreadshellCell & rhs)
{
    if (this == &rhs) {
        return *this;
    }
    mValue = rhs.mValue;
    mString = rhs.mString;
    return *this;
}

SpreadshellCell::SpreadshellCell(double initialValie)
{
    set(initialValie);
}

SpreadshellCell::SpreadshellCell(const std::string& initialValie)
{
    set(initialValie);
}

SpreadshellCell SpreadshellCell::operator+(const SpreadshellCell & cell) const
{
    SpreadshellCell newCell;
    newCell.set(mValue + cell.mValue);
    return newCell;
}

SpreadshellCell::~SpreadshellCell()
{
    mString.~basic_string();
}

SpreadshellCell::SpreadshellCell(SpreadshellCell & src)
{
    mString = src.mString;
    mValue = src.mValue;
}

/************************************************************************/
/* get & set                                                            */
/************************************************************************/
void SpreadshellCell::set(double inValue)
{
    mValue = inValue;
    mString = doubleToString(inValue);
}

double SpreadshellCell::getValue() const
{
    return mValue;
}

void SpreadshellCell::set(const std::string & inString)
{
    mString = inString;
    mValue = stringToDouble(inString);
}

std::string SpreadshellCell::getString() const
{
    mNumberAccesses++;
    return mString;
}

void SpreadshellCell::setColor(Color color)
{
    mColor = color;
}

std::string SpreadshellCell::doubleToString(double inValue) 
{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double SpreadshellCell::stringToDouble(const std::string & inString) 
{
    double temp = 0;
    std::istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }
    return temp;
}
SpreadshellCell SpreadshellCell::operator+(double rhs) const {
    return SpreadshellCell(mValue + rhs);
}