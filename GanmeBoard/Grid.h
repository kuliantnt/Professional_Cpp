#pragma once
#include <vector>
/**
 * \brief ����ģ��
 * \tparam T ����T
 */
template <typename T>
class Grid
{
public:
    /**
     * \brief ���캯��
     * \param inWidth ������
     * \param inHeight ����߶�
     */
    explicit Grid(size_t inWidth = kDefaultWidth,
        size_t inHeight = kDefaultHeight);
    /**
     * \brief ��������
     */
    virtual ~Grid();

    /**
     * \brief ģ�廯�������캯��
     * \tparam E element
     * \param src Դ
     */
    template<typename E>
    Grid( const Grid<E>& src);

    /**
     * \brief ģ�廯��ֵ�����
     * \tparam E element
     * \param rhs 
     * \return 
     */
    template<typename E>
    Grid<T>& operator=(const Grid<E>&rhs);

    /**
     * \brief ����Ԫ��
     * \param x λ��x
     * \param y λ��y
     * \param inElem �����Ԫ��
     */
    void setElementAt(size_t x, size_t y, const T& inElem);
    /**
     * \brief �����趨λ�õ�element
     * \param x λ��x
     * \param y λ��y
     * \return �趨λ�õ�element
     */
    T& getElementAt(size_t x, size_t y);
    /**
     * \brief �����趨λ�õ�const element
     * \param x λ��x
     * \param y λ��y
     * \return �趨λ�õ�const element
     */
    const T& getElementAt(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefaultWidth = 100;
    static const size_t kDefaultHeight = 100;

private:
    /**
     * \brief ģ�廯�Ŀ�������
     * \tparam E element 
     * \param src 
     */
    template<typename E>
    void copyFrom(const Grid<E>& src);
    /**
     * \brief ��ʼ������
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

