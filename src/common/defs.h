#ifndef __DEFS_H__
#define __DEFS_H__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "screen.h"

#include "army.h"
#include "character.h"
#include "coin.h"
#include "enemy.h"
#include "fire.h"
#include "shooting.h"
#include "treasure.h"

#include "menu.h"

/**
    \brief Function for making collision operations.
    \param x1 x-coordinate of the first body
    \param y1 y-coordinate of the first body
    \param w1 Width of the first body
    \param h1 Height of the first body
    \param x2 x-coordinate of the second body
    \param y2 y-coordinate of the second body
    \param w2 Width of the second body
    \param h2 Height of the second body
    \return col Indicates whether there has been a collision between two objects.
*/
int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif // __DEFS_H__
