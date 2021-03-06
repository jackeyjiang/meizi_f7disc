/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter for emWin V5.28.                           *
*        Compiled Jan 30 2015, 16:40:04                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: curtain                                               *
* Dimensions:  94 * 94                                               *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmcurtain;

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _Colorscurtain[] = {
  0x1C1BC5, 0xD9DDF5
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palcurtain = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorscurtain[0]
};

static GUI_CONST_STORAGE unsigned char _accurtain[] = {
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, _XXX____, _____XX_, ________, _______X, XX______, ____XXX_, ________, _______X, X_______, __XXX___, ________,
  ________, _XXX____, _____XX_, ________, XX_____X, XX______, _____XXX, ____XX__, _______X, XX______, __XXX___, ________,
  ________, _XXX____, _____XX_, ________, XX____XX, X_______, _____XXX, ____XXX_, ________, XX______, __XXX___, ________,
  ________, _XXX____, ____XXX_, _______X, XXX___XX, X_______, ______XX, X____XXX, _______X, XX______, __XXX___, ________,
  ________, _XXX____, _____XX_, _______X, XX____XX, X_______, ______XX, X____XXX, ________, XX______, __XXX___, ________,
  ________, _XXX____, ____XX__, ______XX, X____XXX, ________, _______X, XX____XX, X_______, XXX_____, __XXX___, ________,
  ________, _XXX____, ____XX__, ______XX, X____XXX, ________, _______X, XX____XX, X_______, _XX_____, __XXX___, ________,
  ________, _XXX____, ____XX__, _____XXX, X___XXX_, ________, ________, XXX___XX, XX______, _XX_____, __XXX___, ________,
  ________, _XXX____, ___XXX__, _____XXX, ____XXX_, ________, ________, XXX____X, XX______, _XXX____, __XXX___, ________,
  ________, _XXX____, ____XX__, ____XXX_, ___XXX__, ________, ________, _XXX____, XXX_____, _XXX____, __XXX___, ________,
  ________, _XXX____, ___XX___, ___XXXX_, __XXXX__, ________, ________, _XXX____, XXXX____, __XX____, __XXX___, ________,
  ________, _XXX____, ___XX___, ___XXX__, __XXX___, ________, ________, __XXX___, XXXX____, __XX____, __XXX___, ________,
  ________, _XXX____, __XXX___, __XXXX__, _XXX____, ________, ________, __XXX___, _XXX____, __XX____, __XXX___, ________,
  ________, _XXX____, __XX____, __XXX___, XXXX____, ________, ________, ___XXX__, __XXXX__, __XXX___, __XXX___, ________,
  ________, _XXX____, __XX____, _XXX____, XXXX____, ________, ________, ___XXXX_, ___XXX__, ___XX___, __XXX___, ________,
  ________, _XXX____, _XXX____, XXXX___X, XX______, ________, ________, ____XXXX, ____XXX_, ___XX___, __XXX___, ________,
  ________, _XXX____, _XX_____, XXX____X, XX______, ________, ________, _____XXX, ____XXX_, ___XXX__, __XXX___, ________,
  ________, _XXX____, XXX____X, XXX___XX, XX______, ________, ________, ______XX, XX___XXX, X___XXX_, __XXX___, ________,
  ________, _XXX____, XXX___XX, XX___XXX, X_______, ________, ________, ______XX, XX___XXX, X___XXX_, __XXX___, ________,
  ________, _XXX___X, XX___XXX, X___XXXX, ________, ________, ________, ________, XXX___XX, XXX__XXX, __XXX___, ________,
  ________, _XXX___X, XX__XXXX, ___XXXX_, ________, ________, ________, ________, XXXX___X, XXX__XXX, __XXX___, ________,
  ________, _XXX___X, XX_XXXX_, __XXXX__, ________, ________, ________, ________, _XXXX___, XXXXX_XX, __XXX___, ________,
  ________, _XXX__XX, XXXXXX__, _XXXX___, ________, ________, ________, ________, __XXX___, _XXXX_XX, X_XXX___, ________,
  ________, _XXXX_XX, XXXXX___, XXXX____, ________, ________, ________, ________, __XXXXX_, ___XXXXX, X_XXX___, ________,
  ________, _XXXXXXX, XXXX___X, XXX_____, ________, ________, ________, ________, ____XXXX, ___XXXXX, X_XXX___, ________,
  ________, _XXXXXXX, XXX___XX, XX______, ________, ________, ________, ________, _____XXX, XX___XXX, XXXXX___, ________,
  ________, _XXXXXXX, XX__XXXX, X_______, ________, ________, ________, ________, ______XX, XXX__XXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, ________, ________, ________, ________, ________, ________, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXX_, ________, ________, ________, ________, ________, ________, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXX___, ________, ________, ________, ________, ________, ________, __XXXXXX, XXXXX___, ________,
  ________, _XXX____, __XXX___, ________, ________, ________, ________, ________, ________, __XX____, __XXX___, ________,
  ________, _XXX____, ___XXX__, ________, ________, ________, ________, ________, ________, __XX____, __XXX___, ________,
  ________, _XXX____, ___XXX__, ________, ________, ________, ________, ________, ________, _XXX____, __XXX___, ________,
  ________, _XXX____, ___XXX__, ________, ________, ________, ________, ________, ________, _XXX____, __XXX___, ________,
  ________, _XXX____, ____XXX_, ________, ________, ________, ________, ________, ________, XXX_____, __XXX___, ________,
  ________, _XXX____, _____XX_, ________, ________, ________, ________, ________, ________, XXX_____, __XXX___, ________,
  ________, _XXX____, ____XXX_, ________, ________, ________, ________, ________, ________, XXX_____, __XXX___, ________,
  ________, _XXX____, _____XXX, ________, ________, ________, ________, ________, _______X, XX______, __XXX___, ________,
  ________, _XXX___X, ______XX, ________, ________, ________, ________, ________, _______X, XX_____X, __XXX___, ________,
  ________, _XXX__XX, X_____XX, ________, ________, ________, ________, ________, _______X, X_____XX, X_XXX___, ________,
  ________, _XXX___X, X_____XX, ________, ________, ________, ________, ________, ______XX, X_____XX, __XXX___, ________,
  ________, _XXX___X, X_____XX, X_______, ________, ________, ________, ________, ______XX, X_____XX, __XXX___, ________,
  ________, _XXX___X, XX____XX, X_______, ________, ________, ________, ________, ______XX, ______XX, __XXX___, ________,
  ________, _XXX___X, XX_____X, X_______, ________, ________, ________, ________, ______XX, X____XXX, __XXX___, ________,
  ________, _XXX___X, X______X, X_______, ________, ________, ________, ________, ______XX, _____XX_, __XXX___, ________,
  ________, _XXX____, XX_____X, XX______, ________, ________, ________, ________, _____XXX, _____XX_, __XXX___, ________,
  ________, _XXX____, XX_____X, XX______, ________, ________, ________, ________, _____XX_, _____XX_, __XXX___, ________,
  ________, _XXX____, XXX_____, XX______, ________, ________, ________, ________, _____XX_, ____XXX_, __XXX___, ________,
  ________, _XXX____, XX______, XX______, ________, ________, ________, ________, ____XXX_, ____XXX_, __XXX___, ________,
  ________, _XXX____, _XX_____, XX______, ________, ________, ________, ________, _____XX_, ____XX__, __XXX___, ________,
  ________, _XXX____, _XX_____, XX______, ________, ________, ________, ________, ____XXX_, ____XXX_, __XXX___, ________,
  ________, _XXX____, _XX_____, XXX_____, ________, ________, ________, ________, ____XX__, ____XX__, __XXX___, ________,
  ________, _XXX____, _XX_____, XXX_____, ________, ________, ________, ________, ____XX__, ____XX__, __XXX___, ________,
  ________, _XXX____, _XXX____, _XX_____, ________, ________, ________, ________, ____XX__, ____XX__, __XXX___, ________,
  ________, _XXX____, __XX____, XXX_____, ________, ________, ________, ________, ___XXX__, ___XXX__, __XXX___, ________,
  ________, _XXX____, __XX____, _XX_____, ________, ________, ________, ________, ____XX__, ____XX__, __XXX___, ________,
  ________, _XXX____, _XXXX___, _XXX____, ________, ________, ________, ________, ___XX___, ___XXX__, __XXX___, ________,
  ________, _XXX____, __XXX___, _XXX____, ________, ________, ________, ________, ___XXX__, ___XXX__, __XXX___, ________,
  ________, _XXX____, __XX____, _XX_____, ________, ________, ________, ________, ___XXX__, ____XX__, __XXX___, ________,
  ________, _XXX____, __XXX___, _XXX____, ________, ________, ________, ________, ___XXX__, ___XXX__, __XXX___, ________,
  ________, _XXX____, _XXXX___, _XXX____, ________, ________, ________, ________, ___XXX__, ___XX___, __XXX___, ________,
  ________, _XXX____, __XXX___, __XX____, ________, ________, ________, ________, ___XXX__, ___XX___, __XXX___, ________,
  ________, _XXX____, _XXXX___, __XX____, ________, ________, ________, ________, ___XX___, __XXXX__, __XXX___, ________,
  ________, _XXX____, __XXX___, __XXX___, ________, ________, ________, ________, __XXX___, ___XXX__, __XXX___, ________,
  ________, _XXX____, _XXX____, __XXX___, ________, ________, ________, ________, __XXX___, __XXXX__, __XXX___, ________,
  ________, _XXX____, __XXX___, __XXX___, ________, ________, ________, ________, __XXX___, ___XXX__, __XXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXX___, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
};

GUI_CONST_STORAGE GUI_BITMAP bmcurtain = {
  94, // xSize
  94, // ySize
  12, // BytesPerLine
  1, // BitsPerPixel
  _accurtain,  // Pointer to picture data (indices)
  &_Palcurtain   // Pointer to palette
};

/*************************** End of file ****************************/
