#pragma once
#include "SpreadshellCell.h"
class Spreadshell
{
public:
    Spreadshell(int inwidth, int inheight);
    void setCellAt(int x, int y, const SpreadshellCell& cell);
    SpreadshellCell& getCellAt(int x, int y);
    ~Spreadshell();
private:
    bool inRange(int val, int upper);
    int mWidth, mHeight;
    SpreadshellCell** mCells;
};

