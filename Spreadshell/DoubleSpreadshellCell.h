#pragma once
#include "SpreadshellCell.h"
class DoubleSpreadshellCell :
    public SpreadshellCell
{
public:
    DoubleSpreadshellCell();
    virtual ~DoubleSpreadshellCell();
    virtual void set(double inDouble);
    virtual void set(const std::string& inString)  override;
    virtual std::string getString() const override;
private:
    static std::string doubleToString(double inValue);
    static double stringToDouble(const std::string& inValue);
    double mValue;
};

