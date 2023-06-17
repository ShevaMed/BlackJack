#ifndef CARD_H
#define CARD_H


class Card
{
public:
    enum Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    enum Suit { Clubs, Diamonds, Hearts, Spades };

    Card(Rank r, Suit s);

    int getValue() const;
    Rank getRank() const;
    Suit getSuit() const;

private:
    Rank rank_;
    Suit suit_;
};

#endif // CARD_H
