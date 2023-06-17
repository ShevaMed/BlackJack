#ifndef HAND_H
#define HAND_H

#include "card.h"

#include <vector>

class Hand
{
public:
    Hand();

    void addCard(const Card& card);
    int getScore() const;
    void clear();

private:
    std::vector<Card> cards_;

};

#endif // HAND_H
