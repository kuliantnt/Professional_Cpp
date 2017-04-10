#pragma once
#include <string>
class SpreadshellCell
{
public:
    /************************************************************************/
    /* ������ͷź���~                                                        */
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
    /* ����˽�з��� (����ת��)                                                 */
    /************************************************************************/
    std::string doubleToString(double inValue) const;
    double stringToDouble(const std::string& inString) const;
    double mValue;
    std::string mString;
};

