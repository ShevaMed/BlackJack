#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "igame.h"
#include "deck.h"
#include "hand.h"

#include <memory>

class BlackjackGame : IGame
{
public:
    BlackjackGame(int initialBalance);

    void start() override;
    void playerHit() override;
    void playerStand() override;

    void placeBet(int amount);

private:
    std::unique_ptr<Deck> deck_;
    Hand playerHand_;
    Hand dealerHand_;
    int balance_;
    int bet_;
};

#endif // BLACKJACKGAME_H
