/***************************************************************************** 
* @function name : Datebase 
* @author : LianLian
* @date : 2017/4/5 16:58 
* @inParam : 
* @outParam : 
* @last change : 
*****************************************************************************/
#include "Datebase.h"
#include <stdexcept>


namespace Records {
    Datebase::Datebase(): mNextEmployeeNumber(kFirstEmployeeNumber)
    {
    }
    
    Employee & Datebase::addEmployee(const std::string first, const std::string second)
    {
        Employee theEmployee(first, second, mNextEmployeeNumber++);
        theEmployee.hire();
        employees.push_back(theEmployee);
        return employees[employees.size() - 1];
    }

    Employee & Datebase::getEmployee(int employNumber)
    {
        for (auto &iter : employees) 
        {
            if (iter.getEmployeeNumber() == employNumber)
                return iter;
        }
        throw std::runtime_error("No employee found.");
    }

    Employee & Datebase::getEmployee(const std::string first, const std::string second)
    {
        for (auto &iter : employees)
        {
            if (iter.getName() == (first + ' ' + second))
                return iter;
        }
        throw std::runtime_error("No employee found");
    }

    void Datebase::displayAll() const
    {
        for (auto& iter : employees) {
            iter.display();
        }
    }

    void Datebase::displayCurrent() const
    {
        for (auto& iter : employees) {
            if (iter.getHired()) {
                iter.display();
            }
        }
    }

    void Datebase::displayFormer() const
    {
        for (auto& iter : employees) {
            if (!iter.getHired()) {
                iter.display();
            }
        }
    }


    Datebase::~Datebase()
    {
    }

}