#pragma once
#include "SpreadshellCell.h"
class Spreadshell
{
public:
    /************************************************************************/
    /* 构造以及拷贝构造函数                                                    */
    /************************************************************************/
    Spreadshell(int inWidth, int inHeight);
    void setCellAt(int x, int y, const SpreadshellCell& cell);
    Spreadshell(const Spreadshell&src);
    //Spreadshell(Spreadshell&&src);// TODO 2017年4月10日14:54:33
    Spreadshell& operator= (const Spreadshell& src);
    //Spreadshell& operator= (Spreadshell&& src);// TODO 2017年4月10日14:54:45
    /************************************************************************/
    /* get? set?                                                            */
    /************************************************************************/
    SpreadshellCell& getCellAt(int x, int y);
    int getWidth() const;
    int getHeight()const;
    int getID()const;
    /************************************************************************/
    /* destruct funcion                                                     */
    /************************************************************************/
    ~Spreadshell();
    /************************************************************************/
    /* 静态函数成员                                                           */
    /************************************************************************/
    static const int kmaxHeight = 100;
    static const int kmaxWidth = 100;
private:
    void copyForm(const Spreadshell& src);
    bool inRange(int val, int upper);
    int mWidth, mHeight;
    SpreadshellCell** mCells;
    //静态成员函数
    static int sCounter;
    int mID;
};

