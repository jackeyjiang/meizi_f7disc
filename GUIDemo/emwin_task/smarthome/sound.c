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
* Source file: sound                                                 *
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

extern GUI_CONST_STORAGE GUI_BITMAP bmsound;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorssound[] = {
  0x1C1BC5, 0xD9DDF5
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palsound = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorssound[0]
};

static GUI_CONST_STORAGE unsigned char _acsound[] = {
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, XXXXXXXX, XXXXXXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXX__, ________,
  ________, XXXXXXXX, XXXXXXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXX__, ________,
  ________, XXXXXXXX, XXXXXXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, XXX_____, XXX_____, ________, ________, ________, ________, ___XXX__, ___XXXX_, ___XXX__, ________,
  ________, XXX___XX, XXXXX___, XXX_____, ________, ________, ________, ________, ___XXX__, _XXXXXXX, ___XXX__, ________,
  ________, XXX_XXXX, XXXXXX__, XXX_____, ________, ________, ________, ________, ___XXX__, XXXXXXXX, X__XXX__, ________,
  ________, XXXXXXXX, X_XXXXX_, XXX_____, ________, ________, ________, ________, ___XXXX_, XXXX_X_X, XX_XXX__, ________,
  ________, XXXXXXX_, ____XXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XX_____X, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXX_____, ________, ________, ________, ________, ___XXXXX, X_______, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXXX_, ____XXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXXXX, ___XXXXX, XXX_____, ________, ________, ________, ________, ___XXXXX, XXX___XX, XXXXXX__, ________,
  ________, XXX_XXXX, XXXXXX__, XXX_____, ________, ________, ________, ________, ___XXXX_, XXXXXXXX, XX_XXX__, ________,
  ________, XXX__XXX, XXXXXX__, XXX_____, ________, ________, ________, ________, ___XXX__, _XXXXXXX, X__XXX__, ________,
  ________, XXX____X, XXXX____, XXX_____, ________, ________, ________, ________, ___XXX__, ___XXXX_, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXX_____, ________, ________, ________, ________, ___XXX__, ________, ___XXX__, ________,
  ________, XXX_____, XXX_____, XXX_____, ________, ________, ________, ________, ___XXX__, ___XXX__, ___XXX__, ________,
  ________, XXX___XX, XXXX____, XXX_____, ________, ________, ________, ________, ___XXX__, __XXXXX_, ___XXX__, ________,
  ________, XXX__XXX, XXXXX___, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, X__XXX__, ________,
  ________, XXX_XXXX, X_XXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXX_XXX, XX_XXX__, ________,
  ________, XXXXXXXX, ___XXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX____X, XX_XXX__, ________,
  ________, XXXXXX__, ____XXXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XX_____X, XXXXXX__, ________,
  ________, XXXXXXX_, _____XXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, X_______, XXXXXX__, ________,
  ________, XXXXXXX_, ____XXXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXXXX, ___XXXXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XXX___XX, XXXXXX__, ________,
  ________, XXX_XXXX, XXXXXXX_, XXXXXX__, ________, ________, ________, ________, XXXXXX__, XXXXXXXX, XX_XXX__, ________,
  ________, XXX__XXX, XXXXXX__, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, XXXXXXXX, XX_XXX__, ________,
  ________, XXX___XX, XXXXX___, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ___XXXX_, ___XXX__, ________,
  ________, XXX____X, XXXX____, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, __XXXXXX, ___XXX__, ________,
  ________, XXX__XXX, XXXXXX__, XXXXXX__, ________, ________, ________, ________, XXXXXX__, _XXXXXXX, X__XXX__, ________,
  ________, XXX_XXXX, XXXXXX__, XXXXXX__, ________, ________, ________, ________, XXXXXX__, XXXX__XX, XX_XXX__, ________,
  ________, XXX_XXXX, ____XXXX, XXXXXX__, ________, ________, ________, ________, XXXXXX_X, XXX____X, XX_XXX__, ________,
  ________, XXXXXXX_, ____XXXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XX_____X, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, X_______, XXXXXX__, ________,
  ________, XXXXXX__, _____XXX, XXXXXX__, ________, ________, ________, ________, XXXXXXXX, XX______, XXXXXX__, ________,
  ________, XXXXXX__, ____XXXX, XXXXXXXX, X_XX_XXX, X_XXXX_X, XXX_XXXX, _XXXXX_X, XXXXXXXX, X_______, XXXXXX__, ________,
  ________, XXXXXXX_, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX____X, XXXXXX__, ________,
  ________, XXX_XXXX, _XXXXXX_, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX_X, XXXX_XXX, XX_XXX__, ________,
  ________, XXX_XXXX, XXXXXX__, XXXXXXXX, _XX_XX_X, X_XX_XX_, XX_XX_XX, _XX_X_XX, XXXXXX__, XXXXXXXX, XX_XXX__, ________,
  ________, XXX___XX, XXXXX___, XXXXXX__, ________, ________, ________, ________, XXXXXX__, _XXXXXXX, ___XXX__, ________,
  ________, XXX_____, XX______, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ____XX__, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXX_____, ________, XXXXXX__, ________, ________, ________, ________, XXXXXX__, ________, ___XXX__, ________,
  ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________,
  ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________,
  ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, ________,
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

GUI_CONST_STORAGE GUI_BITMAP bmsound = {
  94, // xSize
  94, // ySize
  12, // BytesPerLine
  1, // BitsPerPixel
  _acsound,  // Pointer to picture data (indices)
  &_Palsound   // Pointer to palette
};

/*************************** End of file ****************************/
