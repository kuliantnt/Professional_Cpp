#pragma once
#include "SpreadshellCell.h"
class Spreadshell
{
public:
    /************************************************************************/
    /* 构造以及拷贝构造函数                                                    */
    /************************************************************************/
    Spreadshell(int inwidth, int inheight);
    void setCellAt(int x, int y, const SpreadshellCell& cell);
    Spreadshell(const Spreadshell&src);
    Spreadshell(Spreadshell&&src);
    Spreadshell& operator= (const Spreadshell& src);
    Spreadshell& operator= (Spreadshell&& src);
    /************************************************************************/
    /* get? set?                                                            */
    /************************************************************************/
    SpreadshellCell& getCellAt(int x, int y);
    int getWidth();
    int getHeight();
    ~Spreadshell();
private:
    bool inRange(int val, int upper);
    int mWidth, mHeight;
    SpreadshellCell** mCells;
};

