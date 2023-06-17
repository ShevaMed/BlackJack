#ifndef IGAME_H
#define IGAME_H


class IGame
{
public:
    virtual ~IGame();

    virtual void start() = 0;
    virtual void playerHit() = 0;
    virtual void playerStand() = 0;
};

#endif // IGAME_H
