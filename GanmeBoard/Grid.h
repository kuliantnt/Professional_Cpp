#pragma once
#include <vector>
/**
 * \brief 网格模板
 * \tparam T 类型T
 */
template <typename T>
class Grid
{
public:
    /**
     * \brief 构造函数
     * \param inWidth 输入宽度
     * \param inHeight 输入高度
     */
    explicit Grid(size_t inWidth = kDefaultWidth,
        size_t inHeight = kDefaultHeight);
    /**
     * \brief 析构函数
     */
    virtual ~Grid();

    /**
     * \brief 模板化拷贝构造函数
     * \tparam E element
     * \param src 源
     */
    template<typename E>
    Grid( const Grid<E>& src);

    /**
     * \brief 模板化赋值运算符
     * \tparam E element
     * \param rhs 
     * \return 
     */
    template<typename E>
    Grid<T>& operator=(const Grid<E>&rhs);

    /**
     * \brief 设置元素
     * \param x 位置x
     * \param y 位置y
     * \param inElem 输入的元素
     */
    void setElementAt(size_t x, size_t y, const T& inElem);
    /**
     * \brief 返回设定位置的element
     * \param x 位置x
     * \param y 位置y
     * \return 设定位置的element
     */
    T& getElementAt(size_t x, size_t y);
    /**
     * \brief 返回设定位置的const element
     * \param x 位置x
     * \param y 位置y
     * \return 设定位置的const element
     */
    const T& getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefaultWidth = 100;
    static const size_t kDefaultHeight = 100;

private:
    /**
     * \brief 模板化的拷贝函数
     * \tparam E element 
     * \param src 
     */
    template<typename E>
    void copyFrom(const Grid<E>& src);
    /**
     * \brief 初始化函数
     */
    void initializeCellsContainer();
    std::vector<std::vector<T>> mCells;
    size_t mWidth, mHeight;
};

template<typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight) : mWidth(inWidth), mHeight(inHeight)
{
    initializeCellsContainer();
}

template<typename T>
Grid<T>::~Grid()
{
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
{
    copyFrom(src);
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
    copyFrom(rhs);
    return *this;
}

template<typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T & inElem)
{
    mCells[x][y] = inElem;
}

template<typename T>
T & Grid<T>::getElementAt(size_t x, size_t y)
{
    return mCells[x][y];
}

template<typename T>
const T & Grid<T>::getElementAt(size_t x, size_t y) const
{
    return mCells[x][y];
}

template <typename T>
template <typename E>
void Grid<T>::copyFrom(const Grid<E>& src)
{
    mWidth = src.getWidth();
    mHeight = src.getHeight();
    initializeCellsContainer();
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j != mHeight; j++)
        {
            mCells[i][j] = src.getElementAt(i, j);
        }
    }
}

template<typename T>
void Grid<T>::initializeCellsContainer()
{
    mCells.resize(mWidth);
    for (int i = 0; i != mCells.size(); ++i) {
        mCells[i].resize(mHeight);
    }
}

