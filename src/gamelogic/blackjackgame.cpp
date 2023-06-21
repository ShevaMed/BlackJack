#include "blackjackgame.h"
#include <iostream>
#include <QPainter>
#include <QPaintEvent>
#include <QLayout>
#include <QMessagebox>

BlackjackGame::BlackjackGame(int initialBalance, QWidget *parent) :
    balance_(initialBalance),
    widthCard_(95), heightCard_(148),
    initDeckX_(900), initDeckY_(50),
    initDealerHandX_(150), initDealerHandY_(50),
    initPlayerHandX_(150), initPlayerHandY_(280),
    cardIndent_(15)
{
    deck_ = std::make_unique<Deck>(initDeckX_, initDeckY_, widthCard_, heightCard_, parent);
    dealerHand_ = std::make_unique<Hand>(initDealerHandX_, initDealerHandY_, widthCard_, cardIndent_);
    playerHand_ = std::make_unique<Hand>(initPlayerHandX_, initPlayerHandY_, widthCard_, cardIndent_);

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
}

bool BlackjackGame::playerHit()
{
    this->addCard("Player", false);

    if (playerHand_->getScore() > 21) {
        QMessageBox::information(nullptr, "Game over", "Player busts! You lose.");
        return false;
    }
    return true;
}

void BlackjackGame::playerStand()
{
    while (dealerHand_->getScore() < 17) {
        this->addCard("Dealer", false);
    }

    int playerScore = playerHand_->getScore();
    int dealerScore = dealerHand_->getScore();

    if (dealerScore > 21 || playerScore > dealerScore) {
        QMessageBox::information(nullptr, "Game over", "You win!");
        balance_ += bet_ * 2;

    }
    else if (playerScore < dealerScore) {
        QMessageBox::information(nullptr, "Game over", "Dealer wins!");

    }
    else {
        QMessageBox::information(nullptr, "Game over", "It's a tie!");
        balance_ += bet_;
    }

    if (balance_ <= 0) {
        //Insufficient balance. Game over.

    }
}

bool BlackjackGame::placeBet(int amount)
{
    if (amount <= 0) {
        QMessageBox::warning(nullptr, "Invalid bet", "Place your bet!");
        return false;
    }

    bet_ = amount;
    balance_ -= bet_;
    return true;
}

int BlackjackGame::getBalance() const
{
    return balance_;
}

