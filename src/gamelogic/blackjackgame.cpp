#include "blackjackgame.h"

#include <memory>
#include <QMessageBox>

BlackjackGame::BlackjackGame(int initialBalance, QWidget *parent,
                             QLabel *dealerScore, QLabel *playerScore)
    : initBalance_(initialBalance),
      balance_(initialBalance),
      dealerScore_(dealerScore), playerScore_(playerScore),
      widthCard_(90), heightCard_(140),
      initDeckX_(920), initDeckY_(150),
      initDealerHandX_(170), initDealerHandY_(40),
      initPlayerHandX_(170), initPlayerHandY_(280),
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

    dealerScore_->setText(QString::number(dealerHand_->getScoreCertainCard(1)));
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
        playerScore_->setText(QString::number(playerHand_->getScore()));
    }

    card->setSkin(deck_->getSkinCards());
    card->showCard();
    card->cardAnimation(xEnd, yEnd);
}

bool BlackjackGame::playerHit()
{
    this->addCard("Player", false);

    if (playerHand_->getScore() > 21) {
        this->endGame("You bust!");
        return false;
    }
    return true;
}

void BlackjackGame::playerStand()
{
    while (dealerHand_->getScore() < 17) {
        this->addCard("Dealer",false);
    }

    int playerScore = playerHand_->getScore();
    int dealerScore = dealerHand_->getScore();

    if (dealerScore > 21 || playerScore > dealerScore) {
        balance_ += bet_ * 2;
        this->endGame("You win!");
    }
    else if (playerScore < dealerScore) { 
        this->endGame("Dealer wins!");
    }
    else {
        balance_ += bet_;
        this->endGame("It's a tie!");
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

void BlackjackGame::endGame(QString message)
{
    // show dealer hiden card
    auto& card = dealerHand_->getCard(0);
    card->setHiden(false);
    card->setSkin(deck_->getSkinCards());

    dealerScore_->setText(QString::number(dealerHand_->getScore()));
    QMessageBox::information(nullptr, "Round over", message);
}

int BlackjackGame::getBalance() const
{
    return balance_;
}

void BlackjackGame::resetBalance()
{
    balance_ = initBalance_;
}

void BlackjackGame::changeCardsSkin(QString path)
{
    deck_->loadSkinCards(path);
    deck_->updateSkinCards();
}

