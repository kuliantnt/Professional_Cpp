#pragma once
#include "Grid.h"
template<>
class Grid<const char*>
{
public:
    /**
     * \brief ���캯��
     * \param inWidth ���
     * \param inHeight �߶�
     */
    explicit Grid(size_t inWidth = kDefaultWidth,size_t inHeight = kDefaultHeight);
    /**
     * \brief ��������
     */
    virtual ~Grid();
    /**
     * \brief ����Ԫ��
     * \param x ����x
     * \param y ����y
     * \param inElem �����ֵ
     */
    void setElementAT(size_t x, size_t y, const char* inElem);
    /**
     * \brief ��������Ԫ��
     * \param x ����x
     * \param y ����y
     * \return �����ֵ
     */
    const char* getElementAt(size_t x, size_t y) const;
    /**
     * \brief ���ظ߶�
     * \return Height
     */
    size_t getHeight() const { return mHeight; }
    /**
     * \brief ���ؿ��
     * \return Width
     */
    size_t getWidth() const { return mWidth; }
    /**
     * \brief һ�ѳ���
     */
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;
private:
    /**
     * \brief ��ʼ������
     */
    void initializeCellsContainer();
    std::vector<std::vector<std::string>> mCells;
    size_t mWidth, mHeight;
};

