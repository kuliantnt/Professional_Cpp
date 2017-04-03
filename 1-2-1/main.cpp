#include <iostream>
void func() {
    int* intArray = new int[5]{ 1,2,3,4,5 };
    intArray[3] = 7;
    std::cout << intArray[3] << "\t" << intArray[4] << std::endl;
    delete[] intArray;
}
int main(int argc, char* argv) {
    func();
    system("pause");
}