#include "Employee.h"


namespace Records {
    Employee::Employee() : mfirstname(""),
        mlastname(""), mEmployeeNumber(-1), mSalary(kDefaultStartingSalary), mHired(false)
    {
    }

    Employee::Employee(std::string firstname, std::string lastname, int EmployeeNum, int Salary, bool hired) : mfirstname(firstname),
        mlastname(lastname), mEmployeeNumber(EmployeeNum), mSalary(Salary), mHired(hired)
    {
    }


    Employee::~Employee()
    {
        mfirstname.~basic_string();
        mlastname.~basic_string();
    }
    void Employee::promote(int raiseAmount)
    {
        mSalary += raiseAmount;
    }
    void Employee::demote(int demeritAmount)
    {
        mSalary -= demeritAmount;
    }
    void Employee::hire()
    {
        mHired = true;
    }
    void Employee::fire()
    {
        mHired = false;
    }
    void Employee::display() const
    {
        std::cout << "Employee: " << mfirstname << "," << mlastname << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << (mHired ? "Current Employee" : "Former Employee") << std::endl;
        std::cout << "Employee Number: " << mEmployeeNumber << endl;
        std::cout << "Salaty: $ " << mSalary << std::endl;
        std::cout << std::endl;
    }
}