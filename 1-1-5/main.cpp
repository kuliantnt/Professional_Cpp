#include <iostream>
int main(int argc, char * argv[]) {
    int someInteger = 256;
    short someShort;
    long someLong;
    float someFloat;
    double someDouble;
    someInteger++;
    someShort = static_cast<short> (someInteger);
    someLong = someShort * 10000;
    someFloat = someLong + 0.785f;
    someDouble = static_cast<float>(someFloat) / 100000;
    std::cout << someDouble << std::endl;
    system("pause");
}
