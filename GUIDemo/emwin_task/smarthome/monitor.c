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
* Source file: smart_home_04                                         *
* Dimensions:  50 * 50                                               *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04;
extern GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04_Press;
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
static GUI_CONST_STORAGE GUI_COLOR _Colorssmart_home_04[] = {
  0x000000, 0xFFFFFF
};

static GUI_CONST_STORAGE GUI_COLOR _Colorssmart_home_04_Press[] = {
  0x000000, GUI_BLUE
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palsmart_home_04 = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorssmart_home_04[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palsmart_home_04_Press = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorssmart_home_04_Press[0]
};

static GUI_CONST_STORAGE unsigned char _acsmart_home_04[] = {
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__, _XXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXX____, _XXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______, __XXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ___XXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXX__, ________, ___XXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXX____, ________, ___XXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XX______, ________, __XXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, ________, ________, X_XXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXX__, ________, ______XX, ___XXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXX____, ________, ____XX__, __XXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXX___, ________, __XX____, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXX_XX_, ________, XX____XX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXX___X, X_____XX, _____XXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXX_X___, _XX_XX__, _____XXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXX_____, ___X____, XXX__XXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXX__X__, ______XX, XXX__XXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXX____, ____XXXX, XXX__XXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXX__X_, __XXXXXX, XXX__XXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXXX_XX, _XXXXXXX, XXX_____, ________, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXX_____, ________, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXX_, _XXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXX_X, _XXXXXXX, XXXXXXXX, XX_XXXX_, XXXXXXXX, XX______,
  XXXXXXXX, XXXX_X_X, ____XXXX, XXXXXXXX, XX_X____, __XXXXXX, XX______,
  XXXXXXXX, XXXX_X__, __XXXXXX, XXXXXXXX, XX___XXX, X_XXXXXX, XX______,
  XXXXXXXX, XXXX_X__, XX_XXXXX, XXXXXXXX, XX_XX__X, __XXXXXX, XX______,
  XXXXXXXX, XXXXXX_X, XXXXXXXX, XXXXXXXX, XX___XXX, X_XXXXXX, XX______,
  XXXXXXXX, XXXX____, ____XXXX, XXXXXXXX, X__XX___, __XXXXXX, XX______,
  XXXXXXXX, XXXX_X_X, _XX_XXXX, XXXXXXXX, XX_XXXX_, XXXXXXXX, XX______,
  XXXXXXXX, XXXX_X_X, XXX_XXXX, XXXXXXXX, XX_XXXX_, XXXXXXXX, XX______,
  XXXXXXXX, XXX_____, _____XXX, XXXXXXXX, X__X____, __XXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______,
  XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XX______
};

GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04 = {
  50, // xSize
  50, // ySize
  7, // BytesPerLine
  1, // BitsPerPixel
  _acsmart_home_04,  // Pointer to picture data (indices)
  &_Palsmart_home_04   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmsmart_home_04_Press = {
  50, // xSize
  50, // ySize
  7, // BytesPerLine
  1, // BitsPerPixel
  _acsmart_home_04,  // Pointer to picture data (indices)
  &_Palsmart_home_04_Press   // Pointer to palette
};

/*************************** End of file ****************************/
