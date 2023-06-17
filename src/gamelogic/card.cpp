#include "card.h"

Card::Card(Rank r, Suit s)
    : rank_(r), suit_(s)
{

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
