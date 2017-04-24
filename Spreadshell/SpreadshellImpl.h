#pragma once
#include "SpreadshellCell_old.h"
//===============================================================
//Summary:
//          SpreadshellImpl �࣬ 
//FileName:
//          SpreadshellImpl.h
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          ����(kuliantnt@gmail.com)
//===============================================================
class SpreadshellApplication;
class SpreadshellImpl
{
public:
    /************************************************************************/
    /* �����Լ��������캯��                                                    */
    /************************************************************************/
    SpreadshellImpl() = delete;

    SpreadshellImpl(const SpreadshellApplication& app,int inWidth = kmaxWidth, int inHeight = kmaxHeight);
    SpreadshellImpl(const SpreadshellImpl&src);
    SpreadshellImpl(SpreadshellImpl&&src) noexcept;// TODO 2017��4��10��14:54:33
    SpreadshellImpl& operator= (const SpreadshellImpl& rhs);
    SpreadshellImpl& operator= (SpreadshellImpl&& rhs) noexcept;// TODO 2017��4��10��14:54:45
    /************************************************************************/
    /* get? set?                                                            */
    /************************************************************************/
    SpreadshellCell_old& getCellAt(int x, int y);
    int getWidth() const;
    int getHeight()const;
    int getID()const;
    void setCellAt(int x, int y, const SpreadshellCell_old& cell);
    /************************************************************************/
    /* destruct funcion                                                     */
    /************************************************************************/
    ~SpreadshellImpl();
    /************************************************************************/
    /* ��̬������Ա                                                           */
    /************************************************************************/
    static const int kmaxHeight = 100;
    static const int kmaxWidth = 100;
private:
    //const SpreadshellApplication& mTheApp;
    void copyForm(const SpreadshellImpl& src);
    bool inRange(int val, int upper);
    void freeMemory();
    int mWidth, mHeight;
    SpreadshellCell_old** mCells;
    /************************************************************************/
    /* @brief:��̬������Ա                                                    */
    /************************************************************************/
    static int sCounter;
    int mID;
};

/************************************************************************/
/* @brief:һ��׼��ʵ�ֵ��ࣿ������                                          */
/************************************************************************/
class SpreadshellApplication
{
public:

    SpreadshellApplication& operator=(const SpreadshellApplication& app)  {
        if (this == &app) {
            return *this;
        }
        i = app.i;
        return *this;
    }
private:
    int i;
};