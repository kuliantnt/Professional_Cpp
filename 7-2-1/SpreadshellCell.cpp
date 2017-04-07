/**********************************************************************************************//**
 * @file    SpreadshellCell.cpp.
 *
 * @brief   Implements the spreadshell cell class.
 **************************************************************************************************/

#include "SpreadshellCell.h"
#include <iostream>
#include <sstream>

/**********************************************************************************************//**
 * @fn  SpreadshellCell::SpreadshellCell()
 *
 * @brief   Default constructor.
 *
 * @date    2017/4/7
 **************************************************************************************************/

SpreadshellCell::SpreadshellCell()
{
}

/**********************************************************************************************//**
 * @fn  void SpreadshellCell::setValue(double inValue)
 *
 * @brief   Sets a value.
 *
 * @date    2017/4/6
 *
 * @param   inValue The in value.
 **************************************************************************************************/

void SpreadshellCell::setValue(double inValue)
{
    mValue = inValue;
    mString = doubleToString(inValue);
}

/**********************************************************************************************//**
 * @fn  double SpreadshellCell::getValue() const
 *
 * @brief   Gets the value.
 *
 * @date    2017/4/6
 *
 * @return  The value.
 **************************************************************************************************/

double SpreadshellCell::getValue() const
{
    return mValue;
}

/**********************************************************************************************//**
 * @fn  void SpreadshellCell::setString(const std::string & inString)
 *
 * @brief   Sets a string.
 *
 * @date    2017/4/7
 *
 * @param   inString    The in string.
 **************************************************************************************************/

void SpreadshellCell::setString(const std::string & inString)
{
    mString = inString;
    mValue = stringToDouble(inString);
}

/**********************************************************************************************//**
 * @fn  std::string SpreadshellCell::getString() const
 *
 * @brief   Gets the string.
 *
 * @date    2017/4/7
 *
 * @return  The string.
 **************************************************************************************************/

std::string SpreadshellCell::getString() const
{
    return mString;
}

/**********************************************************************************************//**
 * @fn  std::string SpreadshellCell::doubleToString(double inValue) const
 *
 * @brief   Double to string.
 *
 * @date    2017/4/7
 *
 * @param   inValue The in value.
 *
 * @return  A std::string.
 **************************************************************************************************/

std::string SpreadshellCell::doubleToString(double inValue) const
{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

/**********************************************************************************************//**
 * @fn  double SpreadshellCell::stringToDouble(const std::string & inString) const
 *
 * @brief   String to double.
 *
 * @date    2017/4/7
 *
 * @param   inString    The in string.
 *
 * @return  A double.
 **************************************************************************************************/

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

/**********************************************************************************************//**
 * @fn  SpreadshellCell::~SpreadshellCell()
 *
 * @brief   Destructor.
 *
 * @date    2017/4/7
 **************************************************************************************************/

SpreadshellCell::~SpreadshellCell()
{
    mString.~basic_string();
}
