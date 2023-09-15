#include "defs.h"

Army createArmy(int max)
{
    Army new = malloc(sizeof(struct ArmyRep));
    new->next = NULL;
    new->max = max;
    new->count = 0;
    return new;
}

void freeArmy(Army a)
{
    while (a->next != NULL)
    {
        Army delete = a->next;
        a->next = delete->next;
        freeEnemy(delete->e);
        free(delete);
    }
    free(a);
}

void insertArmy(Army a, Image ir, Image il, int x, int y, int w, int h, int vx)
{
    if (a->count < a->max)
    {
        Army new = malloc(sizeof(struct ArmyRep));
        new->e = createEnemy(ir, il, x, y, w, h, vx);
        new->next = a->next;
        a->next = new;
        a->count++;
    }
}

void drawArmy(Army a)
{
    while (a->next != NULL)
    {
        drawEnemy(a->next->e);
        a = a->next;
    }
}

void moveArmy(Army a)
{
    while (a->next != NULL)
    {
        moveEnemy(a->next->e);
        a = a->next;
    }
}

int collisionArmy(Army a, Character p)
{
    int col = 0;
    while ((a->next) != NULL)
    {
        if (p->i == p->isr)
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 50, a->next->e->h - 70) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
        if (CharacterI(p) == CharacterISL(p))
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 30, a->next->e->h - 50) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
        if (CharacterI(p) == CharacterIRR(p))
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 50, a->next->e->h - 50) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
        if (CharacterI(p) == CharacterIRL(p))
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 30, a->next->e->h - 30) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
        if (CharacterI(p) == CharacterIJR(p))
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 50, a->next->e->h - 70) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
        if (CharacterI(p) == CharacterIJL(p))
        {
            if (CharacterColision(p, a->next->e->x, a->next->e->y, a->next->e->w - 50, a->next->e->h - 70) != 0)
            {
                Army delete = a->next;
                a->next = delete->next;
                freeEnemy(delete->e);
                free(delete);
                col++;
            }
            else
            {
                a = a->next;
            }
        }
    }
    return col;
}

int collisionArmyShooting(Army a, Shooting s)
{
    int col = 0;
    while ((a->next) != NULL)
    {
        if (ShootingColision(s, a->next->e) != 0)
        {
            Army delete = a->next;
            a->next = delete->next;
            freeEnemy(delete->e);
            free(delete);
            a->count--;
            col++;
        }
        else
        {
            a = a->next;
        }
    }
    return col;
}

void animateArmy(Army a) /// Declara las animaciones de cada enemy del ej�rcito
{
    while (a->next != NULL)
    {
        animateEnemy(a->next->e);
        a = a->next;
    }
}
