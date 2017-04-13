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



StringSpreadshellCell::StringSpreadshellCell() : mValue("#NOVALUE")
{
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
