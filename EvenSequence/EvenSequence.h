#pragma once
#include <initializer_list>
#include <iostream>
#include <vector>
class EvenSequence
{
public:
    /************************************************************************/
    /* 构造以及拷贝构造函数                                                    */
    /************************************************************************/
    EvenSequence();
    ~EvenSequence();
    EvenSequence(std::initializer_list < double> args);
    void dump() const;
private:
    std::vector<double> mSequence;
};


