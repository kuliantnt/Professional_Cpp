//===============================================================
//Summary:
//          StringSpreadshellCell 类， 
//FileName:
//          StringSpreadshellCell.h
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          脸脸(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include "SpreadshellCell.h"
#include "DoubleSpreadshellCell.h"
class StringSpreadshellCell :
    public SpreadshellCell
{
public:
    /************************************************************************/
    /* @brief:构造函数                                                       */
    /************************************************************************/
    StringSpreadshellCell();
    StringSpreadshellCell(const DoubleSpreadshellCell& inDoubleShell);
    /************************************************************************/
    /* @brief:重载运算符                                                     */
    /************************************************************************/
    friend StringSpreadshellCell operator+(const StringSpreadshellCell& lhs,
        const StringSpreadshellCell& rhs);
    virtual ~StringSpreadshellCell();
    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;
private:
    std::string mValue;
};

