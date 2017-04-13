#include "DoubleSpreadshellCell.h"
#include <sstream>



DoubleSpreadshellCell::DoubleSpreadshellCell() : 
    mValue(std::numeric_limits<double>::quiet_NaN())
{

}


DoubleSpreadshellCell::~DoubleSpreadshellCell()
{
}

void DoubleSpreadshellCell::set(double inDouble)
{
    mValue = inDouble;
}

void DoubleSpreadshellCell::set(const std::string & inString)
{
    mValue = stringToDouble(inString);
}

std::string DoubleSpreadshellCell::getString() const
{
    return doubleToString(mValue);
}

std::string DoubleSpreadshellCell::doubleToString(double inValue)
{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double DoubleSpreadshellCell::stringToDouble(const std::string & inValue)
{
    std::istringstream istr(inValue);
    double result;
    istr >> result;
    if (istr.fail() || !istr.eof())
        return 0;
    return result;
}
