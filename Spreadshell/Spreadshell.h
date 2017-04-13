#pragma once
//===============================================================
//Summary:
//          Spreadshell 类， 
//FileName:
//          Spreadshell.h
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          脸脸(kuliantnt@gmail.com)
//===============================================================
#include "SpreadshellCell_old.h"
#include "SpreadshellImpl.h"
#include "memory"
class SpreadshellApplication;
class SpreadshellImpl;
class Spreadshell
{
public:
    /************************************************************************/
    /* 构造函数                                                              */
    /************************************************************************/
    Spreadshell();
    Spreadshell(const SpreadshellApplication& theApp, int inWidth, int inHeight);
    Spreadshell(const SpreadshellApplication& theApp);
    Spreadshell(const Spreadshell& src);
    /************************************************************************/
    /* 析构函数                                                              */
    /************************************************************************/
    ~Spreadshell();
    /************************************************************************/
    /* @brief:copy赋值运算符                                                 */
    /************************************************************************/
    Spreadshell& operator= (const Spreadshell&rhs);
    /************************************************************************/
    /* @brief:get&set                                                       */
    /************************************************************************/

    void setCell(int x, int y, const SpreadshellCell_old& inCell);
    SpreadshellCell_old& getCellAt(int x, int y);
    int getid()const;
private:
    /************************************************************************/
    /* @brief:静态变量                                                       */
    /************************************************************************/
    std::unique_ptr<SpreadshellImpl> mImpl;
};

