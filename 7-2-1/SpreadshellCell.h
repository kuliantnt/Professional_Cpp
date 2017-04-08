#pragma once
#include <string>
class SpreadshellCell
{
public:
    /************************************************************************/
    /* 构造和释放函数~                                                        */
    /************************************************************************/
    SpreadshellCell();
    ~SpreadshellCell();
    SpreadshellCell(double initialValie);
    SpreadshellCell(std::string initialValie);
    
    /************************************************************************/
    /* copy construct openator                                              */
    /************************************************************************/
    SpreadshellCell& operator= (const SpreadshellCell& rhs);

    /************************************************************************/
    /* Get and Set                                                          */
    /************************************************************************/
    void setValue(double inValue);
    double getValue() const;
    void setString(const std::string& inString);
    std::string getString() const;
private:
    /************************************************************************/
    /* 两个私有方法 (用于转换)                                                 */
    /************************************************************************/
    std::string doubleToString(double inValue) const;
    double stringToDouble(const std::string& inString) const;
    double mValue;
    std::string mString;
};

