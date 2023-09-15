#ifndef __Pantalla_H__
#define __Pantalla_H__

#include <SDL2/SDL.h>

/**
   \file screen.h
 */

typedef struct Image
{
  SDL_Surface *surface;
} *Image;

typedef struct Screen
{
  int width;
  int height;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Color strokeColor, fillColor;
  int active;
} Screen;

/**
  \brief Function for creating, configuring and activating a graphic window where the result of the different graphic primitives that are applied will appear.
  \param title Window title
  \param w Window width in points
  \param h Window height in points
 */
void create_Screen(char *title, int w, int h);

/**
  \brief Function for freeing the memory reserved for the display and its associated resources.
 */
void free_Screen();

/**
  \brief Function for retrieving the width of the screen.
  \return Window width
*/
int width_Screen();

/**
  \brief Function for retrieving the height of the screen.
  \return Window height
*/
int height_Screen();

/**
  \brief Function for indicating whether the display is active or not. The screen is no longer active when the user closes it.
  \return 1 if the screen is active
  \return 0 if the screen is not active
 */
int isActive_Screen();

/**
 \brief Function for waiting for a certain number of milliseconds.
 \param ms Number of milliseconds to wait
*/
void wait_Screen(int ms);

/**
 * \brief Function for updating the screen. This function must be called after each change in the display to make the changes visible.
 */
void update_Screen();

/**
  \brief Function for indicating whether a particular key is pressed.
  \param scancode Code of the key whose status is to be known. The values corresponding to each key can be found in the SDL 2.0 documentation (https://wiki.libsdl.org/SDL_Scancode).
  \return 1 if the key is pressed
  \return 0 if the key is not pressed
*/
int isKeyPressed_Screen(SDL_Scancode scancode);

/**
  \brief Function for assigning the stroke colour to be used when drawing the edges of drawing primitives.
  \param r Red component of the colour (RGB format) as an integer value between 0 and 255
  \param g Green component of the colour (RGB format) as an integer value between 0 and 255
  \param b Blue component of the colour (RGB format) as an integer value between 0 and 255
  \param a Transparency component of the colour as an integer value between 0 and 255, with 0 being completely transparent and 255 completely opaque
*/
void strokeColor_Screen(int r, int g, int b, int a);

/**
  \brief Function for assigning the fill colour to be used when drawing the interior of drawing primitives.
  \param r Red component of the colour (RGB format) as an integer value between 0 and 255
  \param g Green component of the colour (RGB format) as an integer value between 0 and 255
  \param b Blue component of the colour (RGB format) as an integer value between 0 and 255
  \param a Transparency component of the colour as an integer value between 0 and 255, with 0 being completely transparent and 255 completely opaque
*/
void fillColor_Screen(int r, int g, int b, int a);

/**
  \brief Function for filling the window with the indicated colour, erasing everything that is currently there.
  \param r Red component of the colour (RGB format) as an integer value between 0 and 255
  \param g Green component of the colour (RGB format) as an integer value between 0 and 255
  \param b Blue component of the colour (RGB format) as an integer value between 0 and 255
  \param a Transparency component of the colour as an integer value between 0 and 255, with 0 being completely transparent and 255 completely opaque
*/
void drawBackFilling_Screen(int r, int g, int b, int a);

/**
  \brief Function for drawing a point using the stroke colour.
  \param x Horizontal coordinate of the point
  \param y Vertical coordinate of the point
*/
void drawPoint_Screen(double x, double y);

/**
  \brief Function for drawing a line using the stroke colour.
  \param x1 Horizontal coordinate of one of the ends of the line
  \param y1 Vertical coordinate of one of the ends of the line
  \param x2 Horizontal coordinate of the other end of the line
  \param y2 Vertical coordinate of the other end of the line
*/
void drawLine_Screen(double x1, double y1, double x2, double y2);

/**
  \brief Function for drawing a triangle using the fill colour and the stroke colour for the edges.
  \param x1 Horizontal coordinate of one of the points of the triangle
  \param y1 Vertical coordinate of one of the points of the triangle
  \param x2 Horizontal coordinate of the second of the points of the triangle
  \param y2 Vertical coordinate of the second of the points of the triangle
  \param x3 Horizontal coordinate of the third of the points of the triangle
  \param y3 Vertical coordinate of the third of the points of the triangle
*/
void drawTriangle_Screen(double x1, double y1, double x2, double y2, double x3, double y3);

/**
  \brief Function for drawing a rectangle using the fill colour and the stroke colour for the edges.
  \param x Horizontal coordinate of the upper left corner of the rectangle
  \param y Vertical coordinate of the upper left corner of the rectangle
  \param w Width of the rectangle
  \param h Height of the rectangle
*/
void drawRectangle_Screen(double x, double y, double w, double h);

/**
  \brief Function for drawing a circle using the fill colour and the stroke colour for the edges.
  \param x Horizontal coordinate of the center of the circle
  \param y Vertical coordinate of the center of the circle
  \param r Circle radius
*/
void drawCircle_Screen(double x, double y, double r);

/**
  \brief Function for drawing a text string in the graphic window. The text shown uses a fixed pitch font 8 points wide by 13 points high.
  \param st Character string ending in '\0' to be displayed
  \param x Horizontal coordinate of the upper left corner of the rectangle that frames the text
  \param y Vertical coordinate of the upper left corner of the rectangle that frames the text
*/
void drawText_Screen(char *st, double x, double y);

/**
  \brief Function for displaying a rectangle in which text can be entered. Entry is terminated by pressing ENTER and cancelled by pressing ESC.
  \param x Horizontal coordinate of the upper left corner of the text box
  \param y Vertical coordinate of the upper left corner of the text box
  \param max Maximum number of characters that can be entered
  \param title Message to be displayed above the text box
  \return Pointer to the memory area where space has been reserved for the string or NULL if the entry is cancelled
*/
char *readText_Screen(int x, int y, int max, char *title);

/**
  \pre The file must exist and be in uncompressed BMP format.
  \brief Function for loading into memory an Image stored in a file. The Image must be in BMP format and the full path including the filename must be specified
  \param file Full path to the file containing the Image
  \param transparency Parameter indicating whether the Image is to be considered transparent or not. Any value other than 0 shall tell the function to assume that the colour of the pixel at coordinates (0,0) is to be considered transparent throughout the Image.
  \return The Image loaded into memory. If there is an error, the program ends with an error message
*/
Image readImage_Screen(char *file, int transparency);

/**
  \brief Function for drawing an Image previously loaded in memory.
  \param Image The Image to be drawn
  \param x Horizontal coordinate of the upper left corner of the rectangle containing the Image
  \param y Vertical coordinate of the upper left corner of the rectangle containing the Image
  \param w Width of the Image to be drawn (if it does not match the original size, it is resized)
  \param h Height of the Image to be drawn (if it does not match the original size, it is resized)
*/
void drawImage_Screen(Image Image, double x, double y, double w, double h);

/**
 * \brief Function for retrieving the width of an Image.
 * \param Image The Image whose width is to be known
 * \return The width of the Image
 */
double widthImage_Screen(Image Image);

/**
 * \brief Function for retrieving the height of an Image.
 * \param Image The Image whose height is to be known
 * \return The height of the Image
 */
double heightImage_Screen(Image Image);

/**
 * \brief Function for freeing the memory used by an Image.
 * \param Image The Image to be freed
 */
void freeImage_Screen(Image Image);

/**
  \brief Function for indicating whether any of the mouse buttons are pressed.
  \param button Button number to be checked (1 for left button, 2 for right button, 3 for central button)
  \return 1 if the button is pressed
  \return 0 if the button is not pressed
 */
int isButtonMousePressed_Screen(int button);

/**
  \brief Function for retrieving the coordinates of the mouse.
  \param x Direction where the value of the horizontal coordinate of the mouse is left or NULL if this coordinate is not desired.
  \param y Direction where the value of the vertical coordinate of the mouse is left or NULL if this coordinate is not desired.
*/
void mouseCoords_Screen(double *x, double *y);

#endif
