#pragma once
#include <string>
#include <iostream>
namespace Records {
    //基础起薪是3w美元呢，嗯，美元。
    const int kDefaultStartingSalary = 30000;
    class Employee
    {
    public:
        Employee();
        Employee(std::string firstname, std::string lastname, int EmployeeNum = -1, int Salary = kDefaultStartingSalary, bool mHired = false);
        ~Employee();
        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);
        void hire();
        void fire();
        void display() const;

        //get & set
        std::string getName() const
        {
            return mfirstname + ' ' + mlastname;
        }
        int getEmployeeNumber() const
        {
            return mEmployeeNumber;
        }
        int getSalary() const
        {
            return mSalary;
        }
        void setSalary(int Salary) 
        {
            mSalary = Salary;
        }
        bool getHired() const
        {
            return mHired;
        }
    private:
        std::string mfirstname; //名字
        std::string mlastname; //姓氏
        int mEmployeeNumber; //员工编号
        int mSalary; //工资
        bool mHired; //是否被雇佣
    };
}