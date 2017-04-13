//===============================================================
//Summary:
//          main ¿‡£¨ 
//FileName:
//          main.cpp
//Remarks:
//          ...
//Date:
//          2017/4/13
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#include "StringSpreadshellCell.h"
#include "DoubleSpreadshellCell.h"
#include <vector>
#include <memory>
#include <iostream>
int main(int argc, char * argv[]) 
{
    std::vector<std::unique_ptr<SpreadshellCell>> cellArray;
    cellArray.push_back(std::make_unique<StringSpreadshellCell>());
    cellArray.push_back(std::make_unique<StringSpreadshellCell>());
    cellArray.push_back(std::make_unique<DoubleSpreadshellCell>());

    cellArray[0]->set("hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    std::cout << "Vector values are [" << cellArray[0]->getString() << "," <<
        cellArray[1]->getString() << "," << cellArray[2]->getString() << "]" <<
        std::endl;
    system("pause");
    return 0;
}