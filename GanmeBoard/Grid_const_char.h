#pragma once
#include "Grid.h"
template<>
class Grid<const char*>
{
public:
    /**
     * \brief 构造函数
     * \param inWidth 宽度
     * \param inHeight 高度
     */
    explicit Grid(size_t inWidth = kDefaultWidth,size_t inHeight = kDefaultHeight);
    /**
     * \brief 析构函数
     */
    virtual ~Grid();
    /**
     * \brief 设置元素
     * \param x 坐标x
     * \param y 坐标y
     * \param inElem 输入的值
     */
    void setElementAT(size_t x, size_t y, const char* inElem);
    /**
     * \brief 返回坐标元素
     * \param x 坐标x
     * \param y 坐标y
     * \return 输出的值
     */
    const char* getElementAt(size_t x, size_t y) const;
    /**
     * \brief 返回高度
     * \return Height
     */
    size_t getHeight() const { return mHeight; }
    /**
     * \brief 返回宽度
     * \return Width
     */
    size_t getWidth() const { return mWidth; }
    /**
     * \brief 一堆常量
     */
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;
private:
    /**
     * \brief 初始化函数
     */
    void initializeCellsContainer();
    std::vector<std::vector<std::string>> mCells;
    size_t mWidth, mHeight;
};

