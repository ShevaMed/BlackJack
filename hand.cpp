#include "hand.h"

Hand::Hand()
{

}

void Hand::addCard(const Card &card)
{
    cards_.push_back(card);
}

int Hand::getScore() const
{
    int score = 0;
    int numAces = 0;

    for (const auto& card : cards_) {
        score += card.getValue();

        if (card.getRank() == Card::Ace) {
            ++numAces;
        }
    }

    while (score > 21 && numAces > 0) {
        score -= 10;
        --numAces;
    }

    return score;
}

void Hand::clear()
{
    cards_.clear();
}
