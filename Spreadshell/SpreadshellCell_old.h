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
class SpreadshellCell_old{
public:
    /************************************************************************/
    /* friend                                                               */
    /************************************************************************/
    friend SpreadshellCell_old operator+(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend SpreadshellCell_old operator-(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend SpreadshellCell_old operator*(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend SpreadshellCell_old operator/(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator==(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator<(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator>(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator!=(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator>=(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    friend bool operator<=(const SpreadshellCell_old&lhs, const SpreadshellCell_old&rhs);
    /************************************************************************/
    /* ������ͷź���~                                                        */
    /************************************************************************/
    SpreadshellCell_old() = default;
    ~SpreadshellCell_old();
    SpreadshellCell_old(SpreadshellCell_old& src);
    SpreadshellCell_old(double initialValie);
    explicit SpreadshellCell_old(const std::string& initialValie);
    /************************************************************************/
    /* override operation                                                   */
    /************************************************************************/
    SpreadshellCell_old& operator+= (const SpreadshellCell_old& rhs);
    SpreadshellCell_old& operator-= (const SpreadshellCell_old& rhs);
    SpreadshellCell_old& operator*= (const SpreadshellCell_old& rhs);
    SpreadshellCell_old& operator/= (const SpreadshellCell_old& rhs);

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
    SpreadshellCell_old& operator= (const SpreadshellCell_old& rhs);

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

