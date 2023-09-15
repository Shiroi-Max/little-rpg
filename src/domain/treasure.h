#ifndef __Treasure_H__
#define __Treasure_H__
#include "defs.h"
/**
    \file Treasure
*/

typedef struct TreasureRep
{
    int max, count;
    Coin *c;
} *Treasure;

/**
    \brief Function for storing the treasure in memory.
    \param nmax Maximum number of coins at one time
    \return t Treasure
*/
Treasure createTreasure(int nmax);

/**
    \brief Function for releasing the treasure from memory.
    \param t Treasure
*/
void freeTreasure(Treasure t);

/**
    \brief Function for inserting the treasure on the screen with its image, position and dimensions.
    \param t Treasure
    \param i Image of each treasure coin
    \param x x-coordinate each treasure coin
    \param y y-coordinate each treasure coin
    \param w Width of each treasure coin
    \param h Height of each treasure coin
*/
void insertTreasure(Treasure t, Image i, int x, int y, int w, int h);

/**
    \brief Function for moving the treasure on the screen.
    \param t Treasure
*/
void drawTreasure(Treasure t);

/**
    \brief Function for setting collisions between each treasure coin and a character.
    \param t Treasure
    \param p Character
    \return col Indicates whether there has been a collision between a treasure coin and a character
*/
int collisionTreasure(Treasure t, Character p);

#endif // __Treasure_H__
