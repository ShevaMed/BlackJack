#include "blackjackgame.h"
#include <iostream>

BlackjackGame::BlackjackGame(int initialBalance)
    : deck_(std::make_unique<Deck>()),
      balance_(initialBalance)
{

}

void BlackjackGame::start()
{
    deck_->shuffle();
    playerHand_.clear();
    dealerHand_.clear();

    playerHand_.addCard(deck_->dealCard());
    dealerHand_.addCard(deck_->dealCard());
    playerHand_.addCard(deck_->dealCard());
    dealerHand_.addCard(deck_->dealCard());

    //Player's hand:
    //Dealer's hand:
}

void BlackjackGame::playerHit()
{
    playerHand_.addCard(deck_->dealCard());
    //Player's hand:

    if (playerHand_.getScore() > 21) {
        //Player busts! You lose.

    }
}

void BlackjackGame::playerStand()
{
    while (dealerHand_.getScore() < 17) {
        dealerHand_.addCard(deck_->dealCard());
    }

    //Dealer's hand:

    int playerScore = playerHand_.getScore();
    int dealerScore = dealerHand_.getScore();

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
