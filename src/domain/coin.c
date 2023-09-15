#include "coin.h"

Coin createCoin(Image i, int x, int y, int w, int h)
{
    Coin c = malloc(sizeof(struct CoinRep));
    c->i = i;
    c->x = x;
    c->y = y;
    c->w = w;
    c->h = h;
    return c;
}

void freeCoin(Coin c)
{
    free(c);
}

void drawCoin(Coin c)
{
    Pantalla_DibujaImagen(c->i, c->x, c->y, c->w, c->h);
}

int collisionCoin(Coin c, Character p)
{
    return PersonajeColision(p, c->x, c->y, c->w - 40, c->h - 40);
}
