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
* Source file: upon                                                  *
* Dimensions:  80 * 80                                               *
* NumColors:   2                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"
#include "../MainTask.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmupon;
extern GUI_CONST_STORAGE GUI_BITMAP bmupon;
  
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
static GUI_CONST_STORAGE GUI_COLOR _Colorsupon[] = {
  0x1C1BC5, 0xD9DDF5
};

static GUI_CONST_STORAGE GUI_COLOR _Colorsupon_xg[] = {
  GUI_RED, 0xD9DDF5
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palupon = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsupon[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palupon_xg = {
  2,  // Number of entries
  0,  // No transparency
  &_Colorsupon_xg[0]
};

static GUI_CONST_STORAGE unsigned char _acupon[] = {
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _______X,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ______XX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ______XX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ______XX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ______XX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ______XX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _____XXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _____XXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _____XXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ____XXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ____XXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ____XXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ___XXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ___XXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ___XXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, __XXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, __XXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, __XXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _XXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, _XXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _______X, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _______X, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ______XX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ______XX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _____XXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _____XXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ____XXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ___XXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, ___XXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, __XXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ________, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, _______X, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ______XX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ______XX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, __XXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ______XX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ________, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, _____XXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, _______X, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, ____XXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ________, _XXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ______XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ________, ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ________, ______XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX,
  ______XX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX
};

GUI_CONST_STORAGE GUI_BITMAP bmupon = {
  80, // xSize
  80, // ySize
  10, // BytesPerLine
  1, // BitsPerPixel
  _acupon,  // Pointer to picture data (indices)
  &_Palupon   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmupon_xg = {
  80, // xSize
  80, // ySize
  10, // BytesPerLine
  1, // BitsPerPixel
  _acupon,  // Pointer to picture data (indices)
  &_Palupon_xg   // Pointer to palette
};

/*************************** End of file ****************************/
