#ifndef HAND_H
#define HAND_H

#include "card.h"

#include <vector>

class Hand
{
public:
    Hand(int startX, int startY, int cardWidth, int cardIndent);

    void addCard(const std::shared_ptr<Card>& card);
    int getScore() const;
    int getCurrX_() const;
    int getCurrY_() const;
    void clear();

private:
    std::vector<std::shared_ptr<Card>> cards_;
    int startX_, startY_;
    int currX_;
    int cardWidth_;
    int cardIndent_;

};

#endif // HAND_H
