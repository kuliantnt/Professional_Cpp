#pragma once

#include "Grid.h"
/**
 * \brief GameBoard类，继承与Grid
 * \tparam T 类型T
 */
template <typename T>
class GameBoard : public Grid<T>
{
public:
    /**
     * \brief 构造函数
     * \param inWidth 宽度
     * \param inHeight 高度
     */
    explicit GameBoard(size_t inWidth = Grid<T>::kDefaultWidth, size_t inHeight = Grid<T>::kDefaultHeight);
    /**
     * \brief 移动函数
     * \param xSrc 源x
     * \param ySrc 源y
     * \param xDest 目标x
     * \param yDest 目标y
     */
    void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};



template <typename T>
GameBoard<T>::GameBoard(size_t inWidth, size_t inHeight)
    :Grid<T>(inWidth, inHeight)
{
}

template <typename T>
void GameBoard<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
    Grid<T>::setElementAt(xDest, yDest, Grid<T>::getElementAt(xSrc, ySrc));
    Grid<T>::setElementAt(xSrc, ySrc, T());
}
