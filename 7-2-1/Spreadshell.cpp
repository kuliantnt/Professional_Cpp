#include "Spreadshell.h"


Spreadshell::Spreadshell(int inWidth, int inHeight) :
    mWidth(inWidth), mHeight(inHeight)
{
    mCells = new SpreadshellCell*[inWidth];
    for (int i = 0; i != mWidth; ++i) {
        //todo 2017��4��8��19:29:43o\]\op0
    }
}

Spreadshell::~Spreadshell()
{
}
