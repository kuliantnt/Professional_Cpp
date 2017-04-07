#include "SpreadshellCell.h"
#include <iostream>
#include <sstream>


SpreadshellCell::SpreadshellCell()
{
}

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


SpreadshellCell::~SpreadshellCell()
{
}

SpreadshellCell::SpreadshellCell(double initialValie)
{
    setValue(initialValie);
}

SpreadshellCell::SpreadshellCell(std::string initialValie)
{
    setString(initialValie);
}