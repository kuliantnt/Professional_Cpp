#pragma once
#include "SpreadshellCell.h"
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
    //Spreadshell(Spreadshell&&src);// TODO 2017��4��10��14:54:33
    SpreadshellImpl& operator= (const SpreadshellImpl& src);
    //Spreadshell& operator= (Spreadshell&& src);// TODO 2017��4��10��14:54:45
    /************************************************************************/
    /* get? set?                                                            */
    /************************************************************************/
    SpreadshellCell& getCellAt(int x, int y);
    int getWidth() const;
    int getHeight()const;
    int getID()const;
    void setCellAt(int x, int y, const SpreadshellCell& cell);
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
    const SpreadshellApplication& mTheApp;
    void copyForm(const SpreadshellImpl& src);
    bool inRange(int val, int upper);
    int mWidth, mHeight;
    SpreadshellCell** mCells;
    //��̬��Ա����
    static int sCounter;
    int mID;
};

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