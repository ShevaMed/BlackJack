#ifndef IGAME_H
#define IGAME_H

#include <QString>

class IGame
{
public:
    virtual ~IGame();

    virtual void start() = 0;
    virtual void addCard(QString nameHand, bool hiden) = 0;
    virtual bool playerHit() = 0;
    virtual void playerStand() = 0;
    virtual bool placeBet(int amount) = 0;
    virtual void endGame(QString message) = 0;

};

#endif // IGAME_H
