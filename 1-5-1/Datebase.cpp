#include "Datebase.h"
#include <stdexcept>


namespace Records {
    Datebase::Datebase(): mNextEmployeeNumber(kFirstEmployeeNumber)
    {
    }

    Employee & Datebase::addEmployee(const std::string first, const std::string second)
    {
        Employee theEmployee(first, second, mNextEmployeeNumber++);
        theEmployee.hire;
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


    Datebase::~Datebase()
    {
    }

}