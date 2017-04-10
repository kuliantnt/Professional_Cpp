//===============================================================
//Summary:
//          Datebase ¿‡£¨ 
//FileName:
//          Datebase.h
//Remarks:
//          ...
//Date:
//          2017/4/5
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include "Employee.h"
#include <vector>
namespace Records {
    const int kFirstEmployeeNumber = 10000;
    class Datebase
    {
    public:
        Datebase();
        Employee& addEmployee(const std::string first, const std::string second);
        Employee& getEmployee(int employNumber);
        Employee& getEmployee(const std::string first, const std::string second);
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
        ~Datebase();
    private:
        std::vector<Employee> employees;
        int mNextEmployeeNumber;
    };
}