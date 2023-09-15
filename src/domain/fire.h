#ifndef __Fire_H__
#define __Fire_H__
#include "defs.h"
/**
    \file Fire
*/

typedef struct FireRep
{
    Image i;
    int x, y, w, h, vx, orientation;
} *Fire;

/**
    \brief Function for storing the ball of fire in memory with its image, position and dimensions oriented to the right.
    \param p Character
    \return f Ball of fire
*/
Fire createRightFire(Character p);

/**
    \brief Function for storing the ball of fire in memory with its image, position and dimensions oriented to the left.
    \param p Character
    \return f Ball of fire
*/
Fire createLeftFire(Character p);

/**
    \brief Function for releasing the ball of fire from memory.
    \param f Ball of fire
*/
void freeFire(Fire f);

/**
    \brief Function for drawing the ball of fire on the screen.
    \param f Ball of fire
*/
void drawFire(Fire f);

/**
    \brief Function for moving the ball of fire on the screen.
    \param f Ball of fire
*/
void moveFire(Fire f);

#endif // __Fire_H__
