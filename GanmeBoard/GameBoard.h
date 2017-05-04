#pragma once

#include "Grid.h"
/**
 * \brief GameBoard�࣬�̳���Grid
 * \tparam T ����T
 */
template <typename T>
class GameBoard : public Grid<T>
{
public:
    /**
     * \brief ���캯��
     * \param inWidth ���
     * \param inHeight �߶�
     */
    explicit GameBoard(size_t inWidth = Grid<T>::kDefaultWidth, size_t inHeight = Grid<T>::kDefaultHeight);
    /**
     * \brief �ƶ�����
     * \param xSrc Դx
     * \param ySrc Դy
     * \param xDest Ŀ��x
     * \param yDest Ŀ��y
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
