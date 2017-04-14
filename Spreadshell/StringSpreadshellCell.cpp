//===============================================================
//Summary:
//          StringSpreadshellCell ¿‡£¨ 
//FileName:
//          StringSpreadshellCell.cpp
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#include "StringSpreadshellCell.h"
#include <sstream>



StringSpreadshellCell::StringSpreadshellCell() : mValue("#NOVALUE")
{

}

StringSpreadshellCell::StringSpreadshellCell(const DoubleSpreadshellCell & inDoubleShell)
{
    mValue = inDoubleShell.getString();
}


StringSpreadshellCell::~StringSpreadshellCell()
{
}

void StringSpreadshellCell::set(const std::string & inString)
{
    mValue = inString;
}

std::string StringSpreadshellCell::getString() const
{
    return mValue;
}

StringSpreadshellCell operator+(const StringSpreadshellCell & lhs, const StringSpreadshellCell & rhs)
{
    StringSpreadshellCell newCell;
    newCell.set(lhs.getString() + rhs.getString());
    return newCell; 
}
