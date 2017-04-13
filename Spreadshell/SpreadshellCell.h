//===============================================================
//Summary:
//          SpreadshellCell ¿‡£¨ 
//FileName:
//          SpreadshellCell.h
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include <string>
class SpreadshellCell
{
public:
    SpreadshellCell();
    virtual ~SpreadshellCell();
    virtual void set(const std::string&) = 0;
    virtual std::string getString() const = 0;
};

