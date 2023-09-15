#include "defs.h"

Fire createRightFire(Character p)
{
    Fire f = malloc(sizeof(struct FireRep));
    f->i = Pantalla_ImagenLee("img/Token/Projectiles/Right/1.bmp", 255);
    f->x = p->x + p->w;
    f->y = p->y;
    f->w = 74;
    f->h = 34;
    f->vx = 8;
    f->orientation = 0;
    return f;
}

Fire createLeftFire(Character p)
{
    Fire f = malloc(sizeof(struct FireRep));
    f->i = Pantalla_ImagenLee("img/Token/Projectiles/Left/1.bmp", 255);
    f->x = p->x - 74;
    f->y = p->y;
    f->w = 74;
    f->h = 34;
    f->vx = 8;
    f->orientation = 1;
    return f;
}

void freeFire(Fire f)
{
    free(f);
}

void drawFire(Fire f)
{
    Pantalla_DibujaImagen(f->i, f->x, f->y, f->w, f->h);
}

void moveFire(Fire f)
{
    if (f->orientation == 0)
        f->x += f->vx;
    else
        f->x -= f->vx;
}
