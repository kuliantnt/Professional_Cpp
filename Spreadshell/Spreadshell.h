#pragma once
//===============================================================
//Summary:
//          Spreadshell �࣬ 
//FileName:
//          Spreadshell.h
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          ����(kuliantnt@gmail.com)
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
    /* ���캯��                                                              */
    /************************************************************************/
    Spreadshell();
    Spreadshell(const SpreadshellApplication& theApp, int inWidth, int inHeight);
    Spreadshell(const SpreadshellApplication& theApp);
    Spreadshell(const Spreadshell& src);
    /************************************************************************/
    /* ��������                                                              */
    /************************************************************************/
    ~Spreadshell();
    /************************************************************************/
    /* @brief:copy��ֵ�����                                                 */
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
    /* @brief:��̬����                                                       */
    /************************************************************************/
    std::unique_ptr<SpreadshellImpl> mImpl;
};

