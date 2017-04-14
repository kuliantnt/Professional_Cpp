//===============================================================
//Summary:
//          StringSpreadshellCell �࣬ 
//FileName:
//          StringSpreadshellCell.h
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          ����(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include "SpreadshellCell.h"
#include "DoubleSpreadshellCell.h"
class StringSpreadshellCell :
    public SpreadshellCell
{
public:
    /************************************************************************/
    /* @brief:���캯��                                                       */
    /************************************************************************/
    StringSpreadshellCell();
    StringSpreadshellCell(const DoubleSpreadshellCell& inDoubleShell);
    /************************************************************************/
    /* @brief:���������                                                     */
    /************************************************************************/
    friend StringSpreadshellCell operator+(const StringSpreadshellCell& lhs,
        const StringSpreadshellCell& rhs);
    virtual ~StringSpreadshellCell();
    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;
private:
    std::string mValue;
};

