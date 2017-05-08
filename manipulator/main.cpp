#include <iostream>
#include <cstdio>
#include <iomanip>
#include <time.h>

int main(int argc, char ** argv)
{
    //boolean values
    bool myBool = true;
    std::cout << "This is the default: " << myBool << std::endl;
    std::cout << "This should be true: " << std::boolalpha << std::endl;
    std::cout << "This should be false: " << std::noboolalpha << std::endl;

    //Simulate "%6d" with stream
    int i = 123;
    printf("This should be '  123': %6d\n", i);
    std::cout << "This should be '   123':" << std::setfill('0') << std::setw(6) << i << std::endl;

    //fill with *
    std::cout << "This should be '***123':" << std::setfill('*') << std::setw(6) << i << std::endl;
    std::cout << std::setfill(' ');
    
    //Floating point values
    double db1 = 1.452;
    double db12 = 5;
    std::cout << "This should be ' 5':" << std::setw(2) << std::noshowpoint << db12 <<std::endl;
    std::cout << "This should be @@1.452:" << std::setw(7) << std::setfill('@') << db1 << std::endl;
    //Instructs cout to start formatting numbers according to your loaction.
    //chapter 18 eplains the details of the imbue call and the locale object 
    std::cout.imbue(std::locale(""));
    std::cout << "This is 1234567 formatted according to you location: " << 1234567 <<std::endl;

    //money amount
    std::cout << "This should be a money amount of 120000, "
        << "formatted according to your location: "
        << std::put_money("120000") << std::endl;

    //Date and time
    time_t t_t = time(nullptr); //Get current system time
    tm* t = new tm();
    localtime_s(t,&t_t);
    std::cout << "This should be the current date and time "
        << "formatted according to your location: "
        << std::put_time(t, "%c") << std::endl;
    delete t; 
    //C++14:¡¡Quoted string 
    std::cout << "This should be : \"Quoted string with \\\"embedded quotes\\\".\": "
        << std::quoted("Quoted string with \"embedded quotes\".") << std::endl;
    system("pause");
}
