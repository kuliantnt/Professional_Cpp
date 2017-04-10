/*
#include "Datebase.h"
int main(int argc, char** argv) 
{
    Records::Datebase db;
    Records::Employee& emp1 = db.addEmployee("Greg", "Wallis");
    Records::Employee& emp2 = db.addEmployee("Marc", "Gregoire");
    emp2.setSalary(100000);
    Records::Employee& emp3 = db.addEmployee("John", "DoeGregoire");
    emp3.setSalary(10000);
    emp3.promote();
    std::cout << "all employees: \n" << std::endl;
    db.displayAll();
    std::cout << std::endl << "current employee: " << std::endl << std::endl;
    db.displayCurrent();
    std::cout << std::endl << "former employee: " << std::endl << std::endl;
    db.displayFormer();
    system("pause");
    return 0;
}
*/