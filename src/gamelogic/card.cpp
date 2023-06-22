#include "card.h"

#include <QPainter>
#include <QPropertyAnimation>

Card::Card(Rank r, Suit s, int startX, int startY, int width, int height, QWidget *parent)
    : QWidget(parent),
      rank_(r), suit_(s),
      hiden_(true),
      startX_(startX), startY_(startY)
{
    this->cardReset();
    this->resize(width, height);
}

void Card::cardReset()
{
    this->hide();
    this->move(startX_, startY_);
}

int Card::getValue() const
{
    if (rank_ >= Two && rank_ <= Ten) {
        return rank_;
    }
    else if (rank_ >= Jack && rank_ <= King) {
        return 10;
    }
    else {  // Ace
        return 11;
    }
}

Card::Rank Card::getRank() const
{
    return rank_;
}

Card::Suit Card::getSuit() const
{
    return suit_;
}

bool Card::isHiden() const
{
    return hiden_;
}

int Card::getX() const
{
    return this->x();
}

int Card::getY() const
{
    return this->y();
}

void Card::setHiden(bool hiden)
{
    hiden_ = hiden;
}

void Card::setSkin(QPixmap skinCards)
{
    int width = skinCards.width() / static_cast<int>(Card::Rank::King);
    int height = skinCards.height() / (static_cast<int>(Card::Suit::Spades) + 1);
    int x, y;

    if (hiden_) {
        x = width * 2;
        y = height * 4;
    }
    else {
        x = width * (static_cast<int>(rank_) - 1);
        y = height * (static_cast<int>(suit_) - 1);
    }

    QPixmap skin(width, height);
    skin.fill(Qt::transparent);

    QPainter painter(&skin);
    painter.drawPixmap(0, 0, skinCards, x, y, width, height);
    painter.end();

    skin_ = skin;
    this->update();
}

void Card::showCard()
{
    this->show();
}

void Card::cardAnimation(int xEnd, int yEnd)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(this->x(), this->y()));
    animation->setEndValue(QPoint(xEnd, yEnd));
    animation->setEasingCurve({QEasingCurve::InBack});
    animation->setLoopCount(1);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Card::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(rect(), skin_);
}
