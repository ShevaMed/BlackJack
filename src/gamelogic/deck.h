#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <vector>
#include <QPixmap>

class Deck
{
public:
    Deck(int startX, int startY, int widthCard, int heightCard, QWidget *parent);

    void shuffle();
    const std::shared_ptr<Card>& dealCard();

    void loadSkinCards(QString path);

    QPixmap getSkinCards() const;

    void resetCards();
    void updateSkinCards();

private:
    std::vector<std::shared_ptr<Card>> cards_;
    int currentCardIndex_;
    QPixmap skinCards_;

};

#endif // DECK_H
