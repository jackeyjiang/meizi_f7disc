/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter for emWin V5.30.                           *
*        Compiled Jul  1 2015, 10:49:26                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: server                                                *
* Dimensions:  26 * 20                                               *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmserver_connect;
extern GUI_CONST_STORAGE GUI_BITMAP bmserver_disconnect;
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
static GUI_CONST_STORAGE GUI_COLOR _Colorsserver_connect[] = {
  GUI_BLUE, GUI_LIGHTGRAY
};

static GUI_CONST_STORAGE GUI_COLOR _Colorsserver_disconnect[] = {
  GUI_RED, GUI_LIGHTGRAY
};

static GUI_CONST_STORAGE GUI_COLOR _Colorsserver_init[] = {
  GUI_LIGHTGRAY, GUI_LIGHTGRAY
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palserver_connect = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsserver_connect[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palserver_disconnect = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsserver_disconnect[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palserver_init = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsserver_init[0]
};

static GUI_CONST_STORAGE unsigned char _acserver[] = {
  XXXXXXXX, XX____XX, XXXXXXXX, XX______,
  XXXXXXXX, X_XXXX_X, XXXXXXXX, XX______,
  XXXXXXXX, _XXXXXX_, XXXXXXXX, XX______,
  XXXXXXX_, _XXXXXX_, __XXXXXX, XX______,
  XXXXXXX_, XXXXXXXX, ____XXXX, XX______,
  ________, ___XXXXX, XXX___XX, XX______,
  _XXXXXXX, XX_XXXXX, XXXX_X__, XX______,
  _XXXXXXX, XX_XXXXX, XXXXXXXX, _X______,
  ________, ___XXXXX, XXXXXXXX, ________,
  ________, ___XXXXX, XXXXXXXX, X_______,
  _XXXXXXX, _X_XXXXX, XXXXXXXX, X_______,
  _XXXXXXX, XX_XXXXX, XXXXXXXX, X_______,
  ________, ___XXXXX, XXXXXXXX, ________,
  _XXXXXXX, XX_XXXXX, XXXXXXX_, _X______,
  _XXXXXXX, _X_XX___, ________, XX______,
  ________, ___XX___, ______XX, XX______,
  ________, ___XXXXX, XXXXXXXX, XX______,
  _XXXXXXX, XX_XXXXX, XXXXXXXX, XX______,
  _XXXXXXX, XX_XXXXX, XXXXXXXX, XX______,
  ________, ___XXXXX, XXXXXXXX, XX______
};

GUI_CONST_STORAGE GUI_BITMAP bmserver_connect = {
  26, // xSize
  20, // ySize
  4, // BytesPerLine
  1, // BitsPerPixel
  _acserver,  // Pointer to picture data (indices)
  &_Palserver_connect   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmserver_disconnect = {
  26, // xSize
  20, // ySize
  4, // BytesPerLine
  1, // BitsPerPixel
  _acserver,  // Pointer to picture data (indices)
  &_Palserver_disconnect   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmserver_init = {
  26, // xSize
  20, // ySize
  4, // BytesPerLine
  1, // BitsPerPixel
  _acserver,  // Pointer to picture data (indices)
  &_Palserver_init   // Pointer to palette
};

/*************************** End of file ****************************/
