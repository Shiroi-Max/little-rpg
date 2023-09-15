#include "defs.h"

Shooting createShooting()
{
    Shooting new = malloc(sizeof(struct ShootingRep));
    new->next = NULL;
    return new;
}

void freeShooting(Shooting s)
{
    while (s->next != NULL)
    {
        Shooting delete = s->next;
        s->next = delete->next;
        freeFire(delete->f);
        free(delete);
    }
    free(s);
}

void insertShooting(Shooting s, Character p)
{
    if ((keyPressedScreen(SDL_SCANCODE_C)) && (PersonajeOri(p) == 0))
    {
        Shooting new = malloc(sizeof(struct ShootingRep));
        new->f = createRightFire(p);
        new->next = s->next;
        s->next = new;
    }
    if ((keyPressedScreen(SDL_SCANCODE_C)) && (PersonajeOri(p) == 1))
    {
        Shooting new = malloc(sizeof(struct ShootingRep));
        new->f = createLeftFire(p);
        new->next = s->next;
        s->next = new;
    }
}

void drawShooting(Shooting s)
{
    while (s->next != NULL)
    {
        drawFire(s->next->f);
        s = s->next;
    }
}

void moveShooting(Shooting s)
{
    while (s->next != NULL)
    {
        moveFire(s->next->f);
        if (s->next->f->x != -74 && s->next->f->x != widthScreen() + 74)
        {
            s = s->next;
            continue;
        }
        Shooting delete = s->next;
        s->next = delete->next;
        freeFire(delete->f);
        free(delete);
    }
}

int collisionShooting(Shooting s, Enemy e)
{
    int col = 0;
    while (s->next != NULL)
    {
        if (collisionEnemy(e, s->next->f->x, s->next->f->y, s->next->f->w - 30, s->next->f->h - 20) == 0)
        {
            s = s->next;
            continue;
        }
        Shooting delete = s->next;
        s->next = delete->next;
        freeFire(delete->f);
        free(delete);
        col++;
    }
    return col;
}