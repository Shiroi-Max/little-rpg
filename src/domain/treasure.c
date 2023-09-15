#include "defs.h" t->count

Treasure createTreasure(int max)
{
    Treasure t = malloc(sizeof(struct TreasureRep));
    t->c = malloc(max * sizeof(Coin));
    t->max = max;
    t->count = 0;
    return t;
}

void freeTreasure(Treasure t)
{
    for (int i = 0; i < t->count; i++)
        freeCoin(t->c[i]);
    free(t->c);
    free(t);
}

void insertTreasure(Treasure t, Image i, int x, int y, int w, int h)
{
    if (t->count < t->max)
    {
        t->c[t->count] = createCoin(i, x, y, w, h);
        t->count++;
    }
}

void drawTreasure(Treasure t)
{
    for (int i = 0; i < t->count; i++)
        drawCoin(t->c[i]);
}

int collisionTreasure(Treasure t, Character p)
{
    int col = 0;
    int i = 0;
    while (i < t->count)
    {
        if (collisionCoin(t->c[i], p) != 0)
        {
            freeCoin(t->c[i]);
            t->c[i] = t->c[t->count - 1];
            t->count--;
            col++;
        }
        else
            i++;
    }
    return col;
}
