#include <iostream>
#include "Array.h"
//void func() {
//    int* intArray = new int[5]{ 1,2,3,4,5 };
//    intArray[3] = 7;
//    std::cout << intArray[3] << "\t" << intArray[4] << std::endl;
//    delete[] intArray;
//}
//int main(int argc, char* argv) {
//    func();
//    system("pause");
//}
void printArray(const Array<int> & arr, size_t size)
{
	for(size_t i = 0; i <size;++i)
	{
		std::cout << arr[i] << std::endl;
	}
}
int main(int argc, char ** argv)
{
	Array<int> m_array;
	for (size_t i = 0; i < 10; ++i)
	{
		m_array[i] = 100;
	}
	printArray(m_array, 10);
	system("pause");
}