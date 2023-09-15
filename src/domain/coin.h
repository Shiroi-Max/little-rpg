#ifndef __COIN_H__
#define __COIN_H__
#include "defs.h"
/**
    \file Coin
*/

typedef struct CoinRep
{
    Image i;
    int x, y, w, h;
} *Coin;

/**
    \brief Function for storing the coin in memory with its image, position and dimensions.
    \param i Current image of the coin
    \param x x-coordinate of the coin
    \param y y-coordinate of the coin
    \param w Width of the coin
    \param h Height of the coin
    \return c Coin
*/
Coin createCoin(Image i, int x, int y, int w, int h);

/**
    \brief Function for releasing the coin from memory.
    \param c Coin
*/
void freeCoin(Coin c);

/**
    \brief Function for drawing the coin on the screen.
    \param c Coin
*/
void drawCoin(Coin m);

/**
    \brief Function for setting collisions between the coin and a character.
    \param c Coin
    \param p Character
    \return col Indicates whether there has been a collision between the coin and a character
*/
int collisionCoin(Coin m, Character p);

#endif // __COIN_H__
