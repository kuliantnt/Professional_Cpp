#pragma once
#include <string>
class SpreadshellCell
{
public:
    /************************************************************************/
    /* friend                                                               */
    /************************************************************************/
    friend SpreadshellCell operator+(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator-(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator*(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    friend SpreadshellCell operator/(const SpreadshellCell&lhs, const SpreadshellCell&rhs);
    /************************************************************************/
    /* 构造和释放函数~                                                        */
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
    /* 两个私有方法 (用于转换)                                                 */
    /************************************************************************/
    static std::string doubleToString(double inValue);
    static double stringToDouble(const std::string& inString);
    double mValue = 0.0; 
    std::string mString;
    mutable size_t mNumberAccesses = 0;
    Color mColor = Color::Red;
};

