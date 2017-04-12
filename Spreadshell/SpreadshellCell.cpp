//===============================================================
//Summary:
//          SpreadshellCell 类， 
//FileName:
//          SpreadshellCell.cpp
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          脸脸(kuliantnt@gmail.com)
//===============================================================
#include "SpreadshellCell.h"
#include <iostream>
#include <sstream>

/************************************************************************/
/* 构造函数                                                              */
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


SpreadshellCell & SpreadshellCell::operator+=(const SpreadshellCell & rhs)
{
    this->set(mValue + rhs.mValue);
    return *this;
}

SpreadshellCell & SpreadshellCell::operator-=(const SpreadshellCell & rhs)
{
    this->set(mValue - rhs.mValue);
    return *this;
}

SpreadshellCell & SpreadshellCell::operator*=(const SpreadshellCell & rhs)
{
    this->set(mValue * rhs.mValue);
    return *this;
}

SpreadshellCell & SpreadshellCell::operator/=(const SpreadshellCell & rhs)
{
    if (rhs.mValue == 0) {
        throw std::invalid_argument("不能除以0");
    }
    this->set(mValue / rhs.mValue);
    return *this;
}

SpreadshellCell operator+(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    SpreadshellCell newCell;
    newCell.set(lhs.mValue + rhs.mValue);
    return newCell;
}

SpreadshellCell operator-(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    SpreadshellCell newCell;
    newCell.set(lhs.mValue - rhs.mValue);
    return newCell;
}

SpreadshellCell operator*(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    SpreadshellCell newCell;
    newCell.set(lhs.mValue * rhs.mValue);
    return newCell;
}
SpreadshellCell operator/(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    if (rhs.mValue == 0) {
        throw std::invalid_argument("不能除以0");
    }
    SpreadshellCell newCell;
    newCell.set(lhs.mValue / rhs.mValue);
    return newCell;
}

bool operator==(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue == rhs.mValue);
}

bool operator!=(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue != rhs.mValue);
}

bool operator<(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue < rhs.mValue);
}


bool operator<=(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue <= rhs.mValue);
}

bool operator>(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue > rhs.mValue);
}

bool operator>=(const SpreadshellCell & lhs, const SpreadshellCell & rhs)
{
    return (lhs.mValue >= rhs.mValue);
}
