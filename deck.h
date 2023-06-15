#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <vector>

class Deck
{
public:
    Deck();

    void shuffle();
    Card dealCard();

private:
    std::vector<Card> cards_;
    int currentCardIndex_;

};

#endif // DECK_H
