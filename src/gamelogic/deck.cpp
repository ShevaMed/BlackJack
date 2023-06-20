#include "deck.h"

#include <random>
#include <algorithm>

Deck::Deck(int startX, int startY, int widthCard, int heightCard, QWidget *parent)
    : currentCardIndex_(0)
{
    this->loadSkinCards(":/images/skins/skin1.png");

    for (int suit = Card::Clubs; suit <= Card::Spades; ++suit) {
        for (int rank = Card::Ace; rank <= Card::King; ++rank) {
            cards_.push_back(std::make_shared<Card>(static_cast<Card::Rank>(rank),
                                                    static_cast<Card::Suit>(suit),
                                                    startX, startY, widthCard, heightCard,
                                                    parent));
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);

    currentCardIndex_ = 0;
    cards_[cards_.size() - 1]->setSkin(skinCards_);
    cards_[cards_.size() - 1]->showCard();
}

void Deck::resetCards()
{
    for (int i = 0; i <= currentCardIndex_; ++i) {
        cards_[i]->cardReset();
    }

    cards_[cards_.size() - 1]->cardReset();
}

const std::shared_ptr<Card>& Deck::dealCard()
{
    return cards_[currentCardIndex_++];
}

void Deck::loadSkinCards(QString path)
{
    skinCards_.load(path);
}

QPixmap Deck::getSkinCards() const
{
    return skinCards_;
}
