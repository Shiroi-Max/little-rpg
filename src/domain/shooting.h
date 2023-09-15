#ifndef __SHOOTING_H__
#define __SHOOTING_H__
#include "defs.h"
/**
    \file Shooting
*/

typedef struct ShootingRep
{
    Fire f;
    Shooting next;
} *Shooting;

/**
    \brief Function for storing the shooting in memory.
    \return Shooting
*/
Shooting createShooting();

/**
    \brief Function for releasing the shooting from memory.
    \param s Shooting
*/
void freeShooting(Shooting s);

/**
    \brief Function for inserting the shooting on the screen.
    \param s Shooting
    \param p Character
*/
void insertShooting(Shooting s, Character p);

/**
    \brief Function for moving the shooting on the screen.
    \param s Shooting
*/
void drawShooting(Shooting s);

/**
    \brief Function for moving the shooting on the screen.
    \param s Shooting
*/
void moveShooting(Shooting s);

/**
    \brief Function for setting collisions between the shooting and an enemy.
    \param s Shooting
    \param e Enemy
    \return col Indicates whether there has been a collision between the shooting and an enemy
*/
int collisionShooting(Shooting s, Enemy e);

#endif // __SHOOTING_H__
