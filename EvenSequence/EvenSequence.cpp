#include "EvenSequence.h"
#include <stdexcept>



EvenSequence::EvenSequence()
{
}

EvenSequence::EvenSequence(std::initializer_list<double> args)
{
    if (args.size() % 2 != 0) {
        throw std::invalid_argument("initializer_list should contain even number of elements.");
    }
    mSequence.reserve(sizeof(args));
    mSequence.insert(cend(mSequence), cbegin(args), cend(args));
}

void EvenSequence::dump() const
{
    for (auto value : mSequence) {
        std::cout << value << ",";
    }
    std::cout << std::endl;
}

EvenSequence::~EvenSequence()
{
}
