#pragma once
//===============================================================
//Summary:
//          SpreadshellCell �࣬ 
//FileName:
//          SpreadshellCell.h
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          ����(kuliantnt@gmail.com)
//===============================================================
#include <iostream>
#include <sstream>
class SpreadshellCell{
public:
    /************************************************************************/
    /* friend                                                               */
    /************************************************************************/
    friend SpreadshellCell operator+(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator-(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator*(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator/(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator==(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator<(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator>(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator!=(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator>=(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend bool operator<=(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    /************************************************************************/
    /* ������ͷź���~                                                        */
    /************************************************************************/
    SpreadshellCell() = default;
    ~SpreadshellCell();
    SpreadshellCell(SpreadshellCell& src);
    SpreadshellCell(double initialValie);
    explicit SpreadshellCell(const std::string& initialValie);
    /************************************************************************/
    /* override operation                                                   */
    /************************************************************************/
    SpreadshellCell& operator+= (const SpreadshellCell& rhs);
    SpreadshellCell& operator-= (const SpreadshellCell& rhs);
    SpreadshellCell& operator*= (const SpreadshellCell& rhs);
    SpreadshellCell& operator/= (const SpreadshellCell& rhs);

    /************************************************************************/
    /* set color                                                            */
    /************************************************************************/
    enum class Color {
        Red = 1,
        Green,
        Blue,
        Yello
    };
    /************************************************************************/
    /* copy construct openator                                              */
    /************************************************************************/
    SpreadshellCell& operator= (const SpreadshellCell& rhs);

    /************************************************************************/
    /* Get and Set                                                          */
    /************************************************************************/
    void set(double inValue);
    double getValue() const;
    void set(const std::string& inString);
    std::string getString() const;
    void setColor(Color color);
    
private:
    /************************************************************************/
    /* ����˽�з��� (����ת��)                                                 */
    /************************************************************************/
    static std::string doubleToString(double inValue);
    static double stringToDouble(const std::string& inString);
    double mValue = 0.0; 
    std::string mString;
    mutable size_t mNumberAccesses = 0;
    Color mColor = Color::Red;
};
