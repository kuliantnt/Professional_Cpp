#include "SpreadshellImpl.h"
#include <iostream>
#include <memory>

void printSpreadshell(SpreadshellImpl s)
{
    for (int i = 0; i != s.getWidth(); i++)
    {
        for (int j = 0; j != s.getHeight(); j++)
        {
            std::cout << s.getCellAt(i, j).getValue() << "\t";
        }
        std::cout << std::endl;
    }
}
int main(int argc, char ** argv)
{ 
    /************************************************************************/
    /*  创建表格                                                             */
    /************************************************************************/
    SpreadshellApplication sApp;
    SpreadshellImpl s1(sApp,4, 3);
    printSpreadshell(s1);
    std::cout << "Maximum height is: " << SpreadshellImpl::kmaxHeight << std::endl;
    system("pause");
    return 0;
    /************************************************************************/
    /* 7.2.3_1                                                              */
    /************************************************************************/
    /*
    SpreadshellCell myCell, anotherCell;
    myCell.setValue(3.3);
    anotherCell.setString("5.5");
    std::cout << "Cell(1): " << myCell.getValue() << std::endl;
    std::cout << "Cell(2): " << anotherCell .getValue() << std::endl;
    
    */

    /************************************************************************/
    /* 7.3.1_2                                                              */
    /************************************************************************/
    /*
    SpreadshellCell* myCellp = new SpreadshellCell();
    myCellp->setValue(3.7);
    std::cout << myCellp->getValue() << " " << myCellp->getString() << std::endl;
    delete myCellp;
    myCellp = nullptr;
    system("pause");
    return 0;
    */

    /************************************************************************/
    /*using shared_ptr                                                      */
    /************************************************************************/
    /*
    std::unique_ptr<SpreadshellCell> myCellp(new SpreadshellCell());
    myCellp->setValue(9.9);
    std::cout << myCellp->getValue() << " " << myCellp->getString() << std::endl;
    system("pause");
    return 0;
    */

    /************************************************************************/
    /*using construct function                                              */
    /************************************************************************/
    /*
    SpreadshellCell aThirdCell("Test");
    SpreadshellCell aFourthCell(4.4);
    auto aThirdCellp = std::make_unique<SpreadshellCell>("4.4");
    std::cout << "aThirdCell: " << aThirdCell.getValue() << std::endl;
    std::cout << "aFourthCell: " << aFourthCell.getValue() << std::endl;
    std::cout << "aThiredCellp: " << aThirdCellp->getValue() << std::endl;
    aThirdCellp = nullptr;
    system("pause");
    */
   
}