#include "defs.h"

Enemy createEnemy(Image ir, Image il, int x, int y, int w, int h, int vx)
{
    Enemy e = malloc(sizeof(struct EnemyRep));
    e->ir = ir;
    e->il = il;
    e->i = il;
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;
    e->vx = vx;
    return e;
}

void freeEnemy(Enemy e)
{
    free(e);
}

void drawEnemy(Enemy e)
{
    Pantalla_DibujaImagen(e->i, e->x, e->y, e->w, e->h);
}

void moveEnemy(Enemy e)
{
    e->x -= e->vx;
    if (e->x < -100)
        e->vx *= -1;
    if (e->x > widthScreen() + 100)
        e->vx *= -1;
}

int collisionEnemy(Enemy e, int x, int y, int w, int h)
{
    return collision(e->x, e->y, e->w, e->h, x, y, w, h);
}

void animateEnemy(Enemy e)
{
    if (e->x < -100)
        e->i = e->ir;
    if (e->x > widthScreen() + 100)
        e->i = e->il;
}
