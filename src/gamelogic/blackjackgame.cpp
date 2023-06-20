#include "blackjackgame.h"
#include <iostream>
#include <QPainter>
#include <QPaintEvent>
#include <QLayout>

BlackjackGame::BlackjackGame(int initialBalance, QWidget *parent)
    : QWidget(parent),
      balance_(initialBalance),
      widthCard_(95), heightCard_(148),
      initDeckX_(parent->width() - 150), initDeckY_(50),
      initDealerHandX_(150), initDealerHandY_(100),
      initPlayerHandX_(150), initPlayerHandY_(300),
      cardIndent_(20)
{
    deck_ = std::make_unique<Deck>(initDeckX_, initDeckY_, widthCard_, heightCard_, parent);
    dealerHand_ = std::make_unique<Hand>(initDealerHandX_, initDealerHandY_, widthCard_, cardIndent_);
    playerHand_ = std::make_unique<Hand>(initPlayerHandX_, initPlayerHandY_, widthCard_, cardIndent_);

    this->resize(800, 400);

}

void BlackjackGame::start()
{
    deck_->resetCards();
    deck_->shuffle();
    playerHand_->clear();
    dealerHand_->clear();

    this->addCard("Player", false);
    this->addCard("Dealer", true);
    this->addCard("Player", false);
    this->addCard("Dealer", false);
}

void BlackjackGame::addCard(QString nameHand, bool hiden)
{
    auto& card = deck_->dealCard();
    card->setHiden(hiden);

    int xEnd = card->getX(), yEnd = card->getY();

    if ("Dealer" == nameHand) {
        xEnd = dealerHand_->getCurrX_();
        yEnd = dealerHand_->getCurrY_();
        dealerHand_->addCard(card);
    }
    else if ("Player" == nameHand) {
        xEnd = playerHand_->getCurrX_();
        yEnd = playerHand_->getCurrY_();
        playerHand_->addCard(card);
    }

    card->setSkin(deck_->getSkinCards());
    card->showCard();
    card->cardAnimation(xEnd, yEnd);
    this->parentWidget()->update();
}

void BlackjackGame::playerHit()
{
    this->addCard("Player", false);
    //Player's hand:

    if (playerHand_->getScore() > 21) {
        //Player busts! You lose.

    }
}

void BlackjackGame::playerStand()
{
    while (dealerHand_->getScore() < 17) {
        this->addCard("Dealer", false);
    }

    //Dealer's hand:

    int playerScore = playerHand_->getScore();
    int dealerScore = dealerHand_->getScore();

    if (dealerScore > 21 || playerScore > dealerScore) {
        //Player wins!
        balance_ += bet_;

    }
    else if (playerScore < dealerScore) {
        //Dealer wins!
        balance_ -= bet_;

    }
    else {
        //"It's a tie!

    }

    if (balance_ <= 0) {
        //Insufficient balance. Game over.

    }
}

void BlackjackGame::placeBet(int amount)
{
    if (amount <= 0) {
        //Invalid bet amount.
        return;
    }

    if (amount > balance_) {
        //Insufficient balance to place the bet.
        return;
    }

    bet_ = amount;
    balance_ -= bet_;
    //Bet placed:
}

int BlackjackGame::getBalance() const
{
    return bet_;
}

void BlackjackGame::paintEvent(QPaintEvent *event)
{

}
