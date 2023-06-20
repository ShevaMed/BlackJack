#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "igame.h"
#include "deck.h"
#include "hand.h"

#include <memory>
#include <QWidget>

class BlackjackGame : IGame, QWidget
{
public:
    explicit BlackjackGame(int initialBalance, QWidget *parent = nullptr);

    void start() override;
    void addCard(QString nameHand, bool hiden) override;
    void playerHit() override;
    void playerStand() override;
    void placeBet(int amount) override;

    int getBalance() const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    std::unique_ptr<Deck> deck_;
    std::unique_ptr<Hand> dealerHand_;
    std::unique_ptr<Hand> playerHand_;
    int balance_;
    int bet_;
    int widthCard_, heightCard_;
    int initDeckX_, initDeckY_;
    int initDealerHandX_, initDealerHandY_;
    int initPlayerHandX_, initPlayerHandY_;
    int cardIndent_;
};

#endif // BLACKJACKGAME_H
