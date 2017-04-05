#include <iostream>
#include <stdexcept>
#include <exception>
#include "Datebase.h"


int displayMeun();
void doHire(Records::Datebase& db);
void doFire(Records::Datebase& db);
void doPromote(Records::Datebase& db);
void doDemote(Records::Datebase& db);

int main(int argc, char ** argv) 
{
    Records::Datebase employeeDB;
    bool done = false;
    while (!done) 
    {
        int selection = displayMeun();
        switch (selection) 
        {
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        case 0:
            done = true;
            break;
        default:
            std::cerr << "Unkown command" << std::endl;
            break;
        }
    }
    return 0;
}

int displayMeun()
{
    int selection;
    std::cout << std::endl;
    std::cout << "Employee Database" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) fire an employee" << std::endl;
    std::cout << "3) promote an employee" << std::endl;
    std::cout << "4) list all employee" << std::endl;
    std::cout << "5) list all current employee" <<  std::endl;
    std::cout << "6) list all former employee" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "--->";
    std::cin >> selection;
    return selection;
}
void doHire(Records::Datebase & db)
{
    std::string fristname;
    std::string lastname;
    std::cout << "first name?" << std::endl;
    std::cin >> fristname;
    std::cout << "last name?" << std::endl;
    std::cin >> lastname;
    try {
        db.addEmployee(fristname, lastname);
    }
    catch (const std::exception & e) {
        std::cerr << "Unable to add new employee: " << e.what() << std::endl;
    }
}

void doFire(Records::Datebase & db)
{
    int employeeNumber;
    std::cout << "Employee number?";
    std::cin >> employeeNumber;
    try {
        db.getEmployee(employeeNumber);
    }
    catch (const std::exception& e) {
        std::cerr << "Unable to find this employee: " << e.what() << std::endl;
    }
}

void doPromote(Records::Datebase & db)
{
    int employeeNumber;
    std::cout << "Employee number?";
    std::cin >> employeeNumber;
    try {
        Records::Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        std::cout << "Employee " << employeeNumber << " terminated." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unable to terminate employee:" << e.what() << std::endl;
    }
}

void doDemote(Records::Datebase & db)
{
    int employeeNumber;
    int raiseAmount;
    std::cout << "Employee number?";
    std::cin >> employeeNumber;
    std::cout << "how much of a raise? ";
    std::cin >> raiseAmount;
    try {
        Records::Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    }
    catch (const std::exception& e) {
        std::cerr << "Unable to promote employee:" << e.what() << std::endl;
    }
}
