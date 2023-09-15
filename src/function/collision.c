#include "defs.h"

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    double a1 = pow(w1 / 2, 2);
    double b1 = pow(h1 / 2, 2);
    double a2 = pow(w2 / 2, 2);
    double b2 = pow(h2 / 2, 2);
    double r1 = sqrt(a1 + b1);
    double r2 = sqrt(a2 + b2);

    double c1 = pow((x2 + w2 / 2) - (x1 + w1 / 2), 2);
    double c2 = pow((y2 + h2 / 2) - (y1 + h1 / 2), 2);
    double d = sqrt(c1 + c2);

    int col = 0;
    if (d < r1 + r2)
        col++;
    return col;
}
