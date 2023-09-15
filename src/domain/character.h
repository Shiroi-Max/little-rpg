#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "defs.h"
/**
    \file Character
*/

typedef struct CharacterRep
{
    Image isr, isl, irr, irl, ijr, ijl, i;
    int x, y, w, h, status, orientation;
} *Character;

/**
    \brief Function for storing the character in memory with its images, position, dimensions.
    \param isr Image of the still character oriented to the right
    \param isl Image of the still character oriented to the left
    \param irr Image of the character running oriented to the right
    \param irl Image of the character running oriented to the left
    \param ijr Image of the character jumping oriented to the right
    \param ijl Image of the character jumping oriented to the left
    \param i Current image of the character
    \param x x-coordinate of the character
    \param y y-coordinate of the character
    \param w Width of the character
    \param h Height of the character
    \return p Character
*/
Character createCharacter(Image isr, Image isl, Image irr, Image irl, Image ijr, Image ijl, int x, int y, int w, int h);

/**
    \brief Function for releasing the character from memory.
    \param p Character
*/
void freeCharacter(Character p);

/**
    \brief Function for drawing the character on the screen.
    \param p Character
*/
void drawCharacter(Character p);

/**
    \brief Function for moving the character on the screen.
    \param p Character
    \param vx Character speed on the x-axis
    \param vy Character speed on the y-axis
*/
void moveCharacter(Character p, int vx, int vy);

/**
    \brief Function for setting collisions between the character and an object.
    \param p Character
    \param x x-coordinate of the object
    \param y y-coordinate of the object
    \param w Width of the object
    \param h Height of the object
    \return col Indicates whether there has been a collision between the character and an object
*/
int collisionCharacter(Character p, int x, int y, int w, int h);

/**
    \brief Function for setting the animations of the character.
    \param p Character
*/
void animateCharacter(Character p);

#endif // __CHARACTER_H__
