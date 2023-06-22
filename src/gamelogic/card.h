#ifndef CARD_H
#define CARD_H

#include <QPixmap>
#include <QWidget>

class Card : QWidget
{
public:
    enum Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    enum Suit { Clubs = 1, Diamonds, Hearts, Spades };

    Card(Rank r, Suit s, int startX, int startY, int width, int height, QWidget *parent);

    void cardReset();

    int getValue() const;
    Rank getRank() const;
    Suit getSuit() const;
    bool isHiden() const;
    int getX() const;
    int getY() const;

    void setHiden(bool hiden);
    void setSkin(QPixmap skinCards);

    void showCard();
    void cardAnimation(int xEnd, int yEnd);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Rank rank_;
    Suit suit_;
    bool hiden_;
    QPixmap skin_;
    int startX_, startY_;

};

#endif // CARD_H
