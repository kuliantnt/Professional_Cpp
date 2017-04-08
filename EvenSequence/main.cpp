#include "EvenSequence.h"
int main(int argc, char * argv[]) 
{
    EvenSequence p1{ 1.0,2.0,3.0,4.0,5.0,6.0 };
    p1.dump();
    try {
        EvenSequence p2{ 1.0,2.0,3.0 };
        p2.dump();
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    system("pause");
}