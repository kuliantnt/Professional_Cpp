#pragma once
#include "SpreadshellCell.h"
#include "SpreadshellImpl.h"
#include "memory"
class SpreadshellApplication;
class SpreadshellImpl;
class Spreadshell
{
public:
    Spreadshell();
    Spreadshell(const SpreadshellApplication& theApp, int inWidth, int inHeight);
    Spreadshell(const SpreadshellApplication& theApp);
    Spreadshell(const Spreadshell& src);
    ~Spreadshell();
    Spreadshell& operator= (const Spreadshell&rhs);

    void setCell(int x, int y, const SpreadshellCell& inCell);
    SpreadshellCell& getCellAt(int x, int y);
    int getid()const;
private:
    std::unique_ptr<SpreadshellImpl> mImpl;
};

