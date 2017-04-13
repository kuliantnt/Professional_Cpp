#include "Spreadshell.h"
//===============================================================
//Summary:
//          Spreadshell ¿‡£¨ 
//FileName:
//          Spreadshell.cpp
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================


Spreadshell::Spreadshell()
{
    mImpl = nullptr;
}


Spreadshell::Spreadshell(const SpreadshellApplication & theApp, int inWidth, int inHeight)
{
    mImpl = std::make_unique<SpreadshellImpl>(theApp, inWidth, inHeight);
}

Spreadshell::Spreadshell(const SpreadshellApplication & theApp)
{
    mImpl = std::make_unique<SpreadshellImpl>(theApp);
}

Spreadshell::Spreadshell(const Spreadshell & src)
{
    *mImpl = *src.mImpl;
}


Spreadshell::~Spreadshell()
{
}

Spreadshell & Spreadshell::operator=(const Spreadshell & rhs)
{
    *mImpl = *rhs.mImpl;
    return *this;
}

void Spreadshell::setCell(int x, int y, const SpreadshellCell_old & inCell)
{
    mImpl->setCellAt(x, y, inCell);
}

SpreadshellCell_old & Spreadshell::getCellAt(int x, int y)
{
    return mImpl->getCellAt(x, y);
}

int Spreadshell::getid() const
{
    return mImpl->getID();
}
