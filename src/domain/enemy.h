#ifndef __Enemy_H__
#define __Enemy_H__
#include "defs.h"
/**
    \file Enemy
*/

typedef struct EnemyRep
{
    Image ir, il, i;
    int x, y, w, h, vx;
} *Enemy;

/**
    \brief Function for storing the character in memory with its images, position, dimensions and speed.
    \param ir Image of the enemy oriented to the right
    \param il Image of the enemy oriented to the left
    \param i Current image of the enemy
    \param x x-coordinate of the enemy
    \param y y-coordinate of the enemy
    \param w Width of the enemy
    \param h Height of the enemy
    \param vx Speed on the x-axis of the enemy
    \return e Enemy
*/
Enemy createEnemy(Image ir, Image il, int x, int y, int w, int h, int vx);

/**
    \brief Function for releasing the enemy from memory.
    \param e Enemy
*/
void freeEnemy(Enemy e);

/**
    \brief Function for drawing the enemy on the screen.
    \param e Enemy
*/
void drawEnemy(Enemy e);

/**
    \brief Function for moving the enemy on the screen.
    \param e Enemy
*/
void moveEnemy(Enemy e);

/**
    \brief Function for setting collisions between the enemy and a shooting.
    \param e Enemy
    \param x x-coordinate of the enemy
    \param y y-coordinate of the enemy
    \param w Width of the enemy
    \param h Height of the enemy
    \return col Indicates whether there has been a collision between the enemy and a shooting
*/
int collisionEnemy(Enemy e, int x, int y, int w, int h);

/**
    \brief Function for setting the animations of the enemy.
    \param e Enemy
*/
void animateEnemy(Enemy e);

#endif // __Enemy_H__
