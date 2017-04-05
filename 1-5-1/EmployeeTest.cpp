#include "Employee.h"

int main(int argc, char **argv)
{
    Records::Employee emp("join", "doe", 71, 500000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
    system("pause");
    return 0;
}