#include <new>
#include <iostream>

class PleaseTerminateMe : public std::bad_alloc{};

void myNewHandler()
{
    std::cerr << "Unable to allocator memory." << std::endl;
    throw PleaseTerminateMe();
}

int main(int argc, char ** argv)
{
    try
    {
        std::new_handler oldHandler = std::set_new_handler(myNewHandler);
        size_t numInts = std::numeric_limits<int>::max();
        int*ptr = new int[numInts];
        std::set_new_handler(oldHandler);
    }
    catch(const PleaseTerminateMe&)
    {
        std::cerr << __FILE__ << "(" << __LINE__ << "):Terminating program." << std::endl;
        system("pause");
        return 1;
    }
    return 0;
}