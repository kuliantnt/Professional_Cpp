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
#include "SpreadshellCell_old.h"
#include <iostream>
#include <sstream>

/************************************************************************/
/* 构造函数                                                              */
/************************************************************************/


SpreadshellCell_old & SpreadshellCell_old::operator=(const SpreadshellCell_old & rhs)
{
    if (this == &rhs) {
        return *this;
    }
    mValue = rhs.mValue;
    mString = rhs.mString;
    return *this;
}

SpreadshellCell_old::SpreadshellCell_old(double initialValie)
{
    set(initialValie);
}

SpreadshellCell_old::SpreadshellCell_old(const std::string& initialValie)
{
    set(initialValie);
}

std::ostream& operator<<(std::ostream& os, const SpreadshellCell_old& cell)
{
	os << cell.mString;
	return os;
}

std::istream& operator>>(std::istream& is, SpreadshellCell_old& cell)
{
	std::string temp;
	is >> temp;
	cell.set(temp);
	return is;
}

SpreadshellCell_old::operator double() const
{
	return mValue;
}

SpreadshellCell_old::operator std::string() const
{
	return mString;
}

SpreadshellCell_old::~SpreadshellCell_old()
{
    mString.~basic_string();
}

SpreadshellCell_old::SpreadshellCell_old(SpreadshellCell_old & src)
{
    mString = src.mString;
    mValue = src.mValue;
}

/************************************************************************/
/* get & set                                                            */
/************************************************************************/
void SpreadshellCell_old::set(double inValue)
{
    mValue = inValue;
    mString = doubleToString(inValue);
}

double SpreadshellCell_old::getValue() const
{
    return mValue;
}

void SpreadshellCell_old::set(const std::string & inString)
{
    mString = inString;
    mValue = stringToDouble(inString);
}

std::string SpreadshellCell_old::getString() const
{
    mNumberAccesses++;
    return mString;
}

void SpreadshellCell_old::setColor(Color color)
{
    mColor = color;
}

std::string SpreadshellCell_old::doubleToString(double inValue) 
{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double SpreadshellCell_old::stringToDouble(const std::string & inString) 
{
    double temp = 0;
    std::istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }
    return temp;
}


SpreadshellCell_old & SpreadshellCell_old::operator+=(const SpreadshellCell_old & rhs)
{
    this->set(mValue + rhs.mValue);
    return *this;
}

SpreadshellCell_old & SpreadshellCell_old::operator-=(const SpreadshellCell_old & rhs)
{
    this->set(mValue - rhs.mValue);
    return *this;
}

SpreadshellCell_old & SpreadshellCell_old::operator*=(const SpreadshellCell_old & rhs)
{
    this->set(mValue * rhs.mValue);
    return *this;
}

SpreadshellCell_old & SpreadshellCell_old::operator/=(const SpreadshellCell_old & rhs)
{
    if (rhs.mValue == 0) {
        throw std::invalid_argument("不能除以0");
    }
    this->set(mValue / rhs.mValue);
    return *this;
}

SpreadshellCell_old operator+(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    SpreadshellCell_old newCell;
    newCell.set(lhs.mValue + rhs.mValue);
    return newCell;
}

SpreadshellCell_old operator-(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    SpreadshellCell_old newCell;
    newCell.set(lhs.mValue - rhs.mValue);
    return newCell;
}

SpreadshellCell_old operator*(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    SpreadshellCell_old newCell;
    newCell.set(lhs.mValue * rhs.mValue);
    return newCell;
}
SpreadshellCell_old operator/(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    if (rhs.mValue == 0) {
        throw std::invalid_argument("不能除以0");
    }
    SpreadshellCell_old newCell;
    newCell.set(lhs.mValue / rhs.mValue);
    return newCell;
}

bool operator==(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue == rhs.mValue);
}

bool operator!=(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue != rhs.mValue);
}

bool operator<(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue < rhs.mValue);
}


bool operator<=(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue <= rhs.mValue);
}

bool operator>(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue > rhs.mValue);
}

bool operator>=(const SpreadshellCell_old & lhs, const SpreadshellCell_old & rhs)
{
    return (lhs.mValue >= rhs.mValue);
}
