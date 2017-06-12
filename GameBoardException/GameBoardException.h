#pragma once

class GamePieceExp{};
class GameBoardExp
{
public:
    explicit GameBoardExp(size_t inWidth = kDefaultWidthExp, size_t inHeight = kDefaultHeightExp);
    GameBoardExp(const GameBoardExp& src);
    virtual ~GameBoardExp() noexcept;
    GameBoardExp& operator=(const GameBoardExp& src);
    void setPieceAt(size_t x, size_t y, const GamePieceExp& inPieceExp) const;
    GamePieceExp& getPieceAt (size_t x, size_t y);
    const GamePieceExp& getPieceAt(size_t x, size_t y) const;
    size_t getHeight() const noexcept{ return mHeight; }
    size_t getWidth() const noexcept{ return mWidth; }
    /**
     * \brief 默认长宽
     */
    static const size_t kDefaultWidthExp = 100;
    static const size_t kDefaultHeightExp = 100;
private:
    void copyFrom(const GameBoardExp& src);
    void freeMemory();
    void allocateMemory();
    GamePieceExp** mCells;
    /**
     * \brief 长度和宽度的储存
     */
    size_t mWidth;
    size_t mHeight;
};

