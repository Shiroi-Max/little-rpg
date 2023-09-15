#ifndef __Army_H__
#define __Army_H__
#include "defs.h"

/**
    \file Army
*/

typedef struct ArmyRep
{
    Enemy e;
    Army next;
    int max, count;
} *Army;

/**
    \brief Function for storing the army in memory.
    \param max Maximum number of enemies at one time
    \return a Army
*/
Army createArmy(int max);

/**
    \brief Function for releasing the army from memory.
    \param a Army
*/
void freeArmy(Army a);

/**
    \brief Function for inserting the army on the screen with its picture, position, dimensions and speed.
    \param a Army
    \param ir Image of each enemy of the army oriented to the right
    \param il Image of each enemy of the army oriented to the left
    \param x x-coordinate of each enemy in the army
    \param y y-coordinate of each enemy in the army
    \param w Width of each enemy in the army
    \param h Height of each enemy in the army
    \param vx Speed of each army enemy on the x-axis
*/
void insertArmy(Army a, Image ir, Image il, int x, int y, int w, int h, int vx);

/**
    \brief Function for drawing the army on the screen.
    \param a Army
*/
void drawArmy(Army a);

/**
    \brief Function for moving the army on the screen.
    \param a Army
*/
void moveArmy(Army a);

/**
    \brief Function for setting collisions between each enemy and a character.
    \param a Army
    \param p Character
    \return col Indicates whether there has been a collision between an enemy and a character.
*/
int collisionArmy(Army a, Character p);

/**
    \brief Function for setting collisions between each enemy and a shooting.
    \param a Army
    \param s Shooting
    \return col Indicates whether there has been a collision between an enemy and a shooting.
*/
int collisionArmyShooting(Army a, Shooting s);

/**
    \brief Function for setting the animations of each enemy.
    \param a Army
*/
void animateArmy(Army a);

#endif // __Army_H__
