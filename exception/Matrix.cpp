#include "Matrix.h"
#include <iostream>

Matrix::Matrix(size_t width, size_t height) :mWidth(width), mHeight(height), mMatrix(nullptr)
{
    mMatrix = new Element*[width];
    size_t i = 0;
    try
    {
        for (i = 0; i < width; ++i)
            mMatrix[i] = new Element[height];
    }
    catch(...)
    {
        std::cout << "Exception caught in construtor, cleaning up..." << std::endl;
        for (size_t j = 0; j < i; j++)
        {
            delete[] mMatrix[j];
        }
        delete[] mMatrix;
        mMatrix = nullptr;
        throw std::bad_alloc();
    }
}

Matrix::~Matrix()
{
    for (size_t j = 0; j < mWidth; j++)
    {
        delete[] mMatrix[j];
    }
    delete[] mMatrix;
    mMatrix = nullptr;
}
