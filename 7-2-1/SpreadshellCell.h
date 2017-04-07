/**********************************************************************************************//**
 * @file    SpreadshellCell.h.
 *
 * @brief   Declares the spreadshell cell class.
 **************************************************************************************************/

#pragma once
#include <string>
class SpreadshellCell
{
public:
    SpreadshellCell() = delete;
    ~SpreadshellCell() = default;
    void setValue(double inValue);
    double getValue() const;
    void setString(const std::string& inString);
    std::string getString() const;
private:
    std::string doubleToString(double inValue) const;
    double stringToDouble(const std::string& inString) const;
    double mValue;
    std::string mString;
};

