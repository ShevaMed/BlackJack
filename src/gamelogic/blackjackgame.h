#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "igame.h"
#include "deck.h"
#include "hand.h"

#include <memory>
#include <QLabel>

class BlackjackGame : IGame
{
public:
    BlackjackGame(int initialBalance, QWidget *parent, QLabel *dealerScore, QLabel *playerScore);

    void start() override;
    void addCard(QString nameHand, bool hiden) override;
    bool playerHit() override;
    void playerStand() override;
    bool placeBet(int amount) override;
    void endGame(QString message) override;

    int getBalance() const;
    void resetBalance();
    void changeCardsSkin(QString path);

private:
    std::unique_ptr<Deck> deck_;
    std::unique_ptr<Hand> dealerHand_;
    std::unique_ptr<Hand> playerHand_;
    int initBalance_;
    int balance_;
    int bet_;
    QLabel *dealerScore_, *playerScore_;
    int widthCard_, heightCard_;
    int initDeckX_, initDeckY_;
    int initDealerHandX_, initDealerHandY_;
    int initPlayerHandX_, initPlayerHandY_;
    int cardIndent_;

};

#endif // BLACKJACKGAME_H
