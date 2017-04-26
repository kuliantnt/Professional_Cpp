#pragma once
#include <vector>
template <typename T>
class Grid
{
public:
    explicit Grid(size_t inWidth = kDefualtWidth,
        size_t inHeight = kDefualtHeight);
    virtual ~Grid();

    void setElementAt(size_t x, size_t y, const T& inElem);
    T& getElementAt(size_t x, size_t y);
    const T& getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefualtWidth = 100;
    static const size_t kDefualtHeight = 100;

private:
    void initializeCellsContainer();
    std::vector<std::vector<T>> mCells;
    size_t mWidth, mHeight;
};


