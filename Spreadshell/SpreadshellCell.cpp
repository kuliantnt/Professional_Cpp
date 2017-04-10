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
    setValue(initialValie);
}

SpreadshellCell::SpreadshellCell(std::string initialValie)
{
    setString(initialValie);
}

SpreadshellCell::~SpreadshellCell()
{
    mString.~basic_string();
}

/************************************************************************/
/* get & set                                                            */
/************************************************************************/
void SpreadshellCell::setValue(double inValue)
{
    mValue = inValue;
    mString = doubleToString(inValue);
}

double SpreadshellCell::getValue() const
{
    return mValue;
}

void SpreadshellCell::setString(const std::string & inString)
{
    mString = inString;
    mValue = stringToDouble(inString);
}

std::string SpreadshellCell::getString() const
{
    return mString;
}

std::string SpreadshellCell::doubleToString(double inValue) const
{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double SpreadshellCell::stringToDouble(const std::string & inString) const
{
    double temp = 0;
    std::istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }
    return temp;
}
