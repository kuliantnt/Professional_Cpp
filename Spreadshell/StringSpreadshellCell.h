//===============================================================
//Summary:
//          StringSpreadshellCell ¿‡£¨ 
//FileName:
//          StringSpreadshellCell.h
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include "SpreadshellCell.h"
class StringSpreadshellCell :
    public SpreadshellCell
{
public:
    StringSpreadshellCell();
    virtual ~StringSpreadshellCell();
    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;
private:
    std::string mValue;
};

