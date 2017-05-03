#pragma once
#include <vector>
template <typename T>
class Grid
{
public:
    explicit Grid(size_t inWidth = kDefualtWidth,
        size_t inHeight = kDefualtHeight);
    virtual ~Grid();

    /**
     * \brief 模板化构造函数
     * \tparam E 
     * \param src 
     */
    template<typename E>
    Grid(const Grid<E>& src);

    /**
     * \brief 模板化赋值运算符
     * \tparam E element
     * \param rhs 
     * \return 
     */
    template<typename E>
    Grid<T>& operator=(const Grid<E>&rhs);

    void setElementAt(size_t x, size_t y, const T& inElem);
    T& getElementAt(size_t x, size_t y);
    const T& getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefualtWidth = 100;
    static const size_t kDefualtHeight = 100;

private:
    /**
     * \brief 模板化的拷贝函数
     * \tparam E element 
     * \param src 
     */
    template<typename E>
    void copyFrom(const Grid<E>& src);
    void initializeCellsContainer();
    std::vector<std::vector<T>> mCells;
    size_t mWidth, mHeight;
};


