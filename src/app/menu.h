#ifndef __Menu_H__
#define __Menu_H__
#include "defs.h"
/**
    \file Menu
*/

typedef struct MenuRep
{
    Image ibo, ico, ico1, ico2, ict, ict1, ict2, iex, iex1, iex2;
    int x, y, w, h, state;
} *Menu;

/**
    \brief Function for storing the menu in memory with its images, position, dimensions.
    \param ibo Image of menu_box
    \param ico1 Image of continue
    \param ico2 Image of continue(on)
    \param ict1 Image of controls
    \param ict2 Image of controls(on)
    \param iex1 Image of exit
    \param iex2 Image of exit(on)
    \param x x-coordinate of the character
    \param y y-coordinate of the character
    \param w Width of the character
    \param h Height of the character
    \return m Menu
*/
Menu createMenu(Image ibo, Image ico1, Image ico2, Image ict1, Image ict2, Image iex1, Image iex2, int x, int y, int w, int h);

/**
    \brief Function for releasing the menu from memory.
    \param m Menu
*/
void freeMenu(Menu m);

/**
    \brief Function for drawing the menu on the screen.
    \param m Menu
*/
void drawMenu(Menu m);

/**
    \brief Function for declaring the menu's actions.
    \param m Menu
    \return m->state Menu's state
*/
int actionMenu(Menu m);

#endif // __Menu_H__
