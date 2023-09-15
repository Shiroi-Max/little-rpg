#include "character.h"

Character createCharacter(Image isr, Image isl, Image irr, Image irl, Image ijr, Image ijl, int x, int y, int w, int h)
{
    Character p = malloc(sizeof(struct CharacterRep));
    p->isr = isr;
    p->isl = isl;
    p->irr = irr;
    p->irl = irl;
    p->ijr = ijr;
    p->ijl = ijl;
    p->i = isr;
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    p->status = 0;
    p->orientation = 0;
    return p;
}

void freeCharacter(Character p)
{
    free(p);
}

void drawCharacter(Character p)
{
    Pantalla_DibujaImagen(p->i, p->x, p->y, p->w, p->h);
}

void moveCharacter(Character p, int vx, int vy)
{
    switch (p->status)
    {
    case 0: /// Reposo
        if (keyPressedScreen(SDL_SCANCODE_SPACE))
            p->status = 1;
        break;
    case 1: /// Subida
        p->y -= vy;
        if (p->y == heightScreen() - 300)
            p->status = 2;
        break;
    case 2: /// Bajada
        p->y += vy;
        if (p->y == heightScreen() - 160)
            p->status = 0;
    }
    if (keyPressedScreen(SDL_SCANCODE_A) || keyPressedScreen(SDL_SCANCODE_LEFT))
        p->x -= vx;
    if (keyPressedScreen(SDL_SCANCODE_D) || keyPressedScreen(SDL_SCANCODE_RIGHT))
        p->x += vx;
    if (p->x < 0)
        p->x = 0;
    if (p->x > widthScreen() - p->w)
        p->x = widthScreen() - p->w;
}

int collisionCharacter(Character p, int x, int y, int w, int h)
{
    return colision(p->x, p->y, p->w, p->h, x, y, w, h);
}

void animateCharacter(Character p)
{
    switch (p->status)
    {
    case 0:
        if (p->orientation == 0)
        {
            p->i = p->isr;
            p->w = 50;
            p->h = 70;
            p->y = heightScreen() - 160;
        }
        if (p->orientation == 1)
        {
            p->i = p->isl;
            p->w = 50;
            p->h = 70;
            p->y = heightScreen() - 160;
        }
        if (keyPressedScreen(SDL_SCANCODE_D) || keyPressedScreen(SDL_SCANCODE_RIGHT))
        {
            p->i = p->irr;
            p->w = 50;
            p->h = 50;
            p->y = heightScreen() - 140;
            p->orientation = 0;
        }
        if (keyPressedScreen(SDL_SCANCODE_A) || keyPressedScreen(SDL_SCANCODE_LEFT))
        {
            p->i = p->irl;
            p->w = 50;
            p->h = 50;
            p->y = heightScreen() - 140;
            p->orientation = 1;
        }
        if (keyPressedScreen(SDL_SCANCODE_SPACE))
            p->status = 1;
        break;
    case 1:
        if (keyPressedScreen(SDL_SCANCODE_D) || keyPressedScreen(SDL_SCANCODE_RIGHT))
            p->orientation = 0;
        if (keyPressedScreen(SDL_SCANCODE_A) || keyPressedScreen(SDL_SCANCODE_LEFT))
            p->orientation = 1;
        if (p->orientation == 0)
        {
            p->i = p->ijr;
            p->w = 50;
            p->h = 70;
        }
        if (p->orientation == 1)
        {
            p->i = p->ijl;
            p->w = 50;
            p->h = 70;
        }
        break;
    case 2:
        if (keyPressedScreen(SDL_SCANCODE_D) || keyPressedScreen(SDL_SCANCODE_RIGHT))
            p->orientation = 0;
        if (keyPressedScreen(SDL_SCANCODE_A) || keyPressedScreen(SDL_SCANCODE_LEFT))
            p->orientation = 1;
        if (p->orientation == 0)
        {
            p->i = p->ijr;
            p->w = 50;
            p->h = 70;
        }
        if (p->orientation == 1)
        {
            p->i = p->ijl;
            p->w = 50;
            p->h = 70;
        }
    }
}