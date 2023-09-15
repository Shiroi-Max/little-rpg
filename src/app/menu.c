#include "defs.h"

Menu createMenu(Image ibo, Image ico1, Image ico2, Image ict1, Image ict2, Image iex1, Image iex2, int x, int y, int w, int h)
{
    Menu m = malloc(sizeof(struct MenuRep));
    m->ibo = ibo;
    m->ico = ico1;
    m->ico1 = ico1;
    m->ico2 = ico2;
    m->ict = ict1;
    m->ict1 = ict1;
    m->ict2 = ict2;
    m->iex = iex1;
    m->iex1 = iex1;
    m->iex2 = iex2;
    m->x = x;
    m->y = y;
    m->w = w;
    m->h = h;
    m->state = 0;
    return m;
}

void freeMenu(Menu m)
{
    free(m);
}

void drawMenu(Menu m)
{
    Pantalla_DibujaImagen(m->ibo, m->x, m->y, m->w, m->h);
    Pantalla_DibujaImagen(m->ico, widthScreen() - 455, heightScreen() - 360, 113, 19);
    Pantalla_DibujaImagen(m->ict, widthScreen() - 455, heightScreen() - 305, 113, 19);
    Pantalla_DibujaImagen(m->iex, widthScreen() - 428, heightScreen() - 253, 57, 19);

    if (m->state == 1)
        m->ico = m->ico2;
    if (m->state != 1)
        m->ico = m->ico1;

    if (m->state == 2)
        m->ict = m->ict2;
    if (m->state != 2)
        m->ict = m->ict1;

    if (m->state == 3)
        m->iex = m->iex2;
    if (m->state != 3)
        m->iex = m->iex1;
}

int actionMenu(Menu m)
{
    double mousex, mousey;
    mouseCoords_Screen(&mousex, &mousey);

    if ((mousex > widthScreen() - 455) && (mousex < widthScreen() - 345) && (mousey > heightScreen() - 360) && (mousey < heightScreen() - 343))
        m->state = 1;
    else if ((mousex > widthScreen() - 455) && (mousex < widthScreen() - 344) && (mousey > heightScreen() - 310) && (mousey < heightScreen() - 287))
        m->state = 2;
    else if ((mousex > widthScreen() - 428) && (mousex < widthScreen() - 373) && (mousey > heightScreen() - 253) && (mousey < heightScreen() - 235))
        m->state = 3;
    else
        m->state = 0;

    return m->state;
}
