#include "hand.h"

Hand::Hand(int startX, int startY, int cardWidth, int cardIndent) :
    startX_(startX), startY_(startY),
    currX_(startX),
    cardWidth_(cardWidth),
    cardIndent_(cardIndent)
{

}

void Hand::addCard(const std::shared_ptr<Card>& card)
{
    cards_.push_back(card);
    currX_ += cardWidth_ + cardIndent_;
}

int Hand::getScore() const
{
    int score = 0;
    int numAces = 0;

    for (const auto& card : cards_) {
        score += card->getValue();

        if (card->getRank() == Card::Rank::Ace) {
            ++numAces;
        }
    }

    while (score > 21 && numAces > 0) {
        score -= 10;
        --numAces;
    }

    return score;
}

int Hand::getScoreCertainCard(int index) const
{
    return cards_[index]->getValue();
}

int Hand::getCurrX_() const
{
    return currX_;
}

int Hand::getCurrY_() const
{
    return startY_;
}

const std::shared_ptr<Card> &Hand::getCard(int index) const
{
    return cards_[index];
}

void Hand::clear()
{
    cards_.clear();
    currX_ = startX_;
}
