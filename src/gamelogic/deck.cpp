#include "deck.h"

#include <random>
#include <algorithm>

Deck::Deck()
    : currentCardIndex_(0)
{
    for (int suit = Card::Clubs; suit <= Card::Spades; ++suit) {
        for (int rank = Card::Ace; rank <= Card::King; ++rank) {
            cards_.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);
    currentCardIndex_ = 0;
}

Card Deck::dealCard()
{
    return cards_[currentCardIndex_++];
}
