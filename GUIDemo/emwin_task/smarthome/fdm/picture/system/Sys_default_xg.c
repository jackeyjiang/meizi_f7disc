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
* Source file: Sys_default_xg                                        *
* Dimensions:  94 * 94                                               *
* NumColors:   3                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmSys_default_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_default;
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
static GUI_CONST_STORAGE GUI_COLOR _ColorsSys_default_xg[] = {
  0xA58523, 0x9C7300, 0xF4F1E5
};

static GUI_CONST_STORAGE GUI_COLOR _ColorsSys_default[] = {
  GUI_DARKBLUE, 0x9C7300, 0xF4F1E5
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalSys_default_xg = {
  3,  // Number of entries
  0,  // No transparency
  &_ColorsSys_default_xg[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalSys_default = {
  3,  // Number of entries
  0,  // No transparency
  &_ColorsSys_default[0]
};

static GUI_CONST_STORAGE unsigned char _acSys_default_xg[] = {
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x4A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x15, 0x55, 0x50,
  0x55, 0x55, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA5, 0x55, 0x50,
  0x55, 0x52, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x55, 0x50,
  0x55, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x55, 0x50,
  0x55, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x50,
  0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x0A, 0xAA, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0xAA, 0xAA, 0xA0, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x02, 0xAA, 0xAA, 0xA8, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x0A, 0xAA, 0x0A, 0xAA, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x2A, 0xA0, 0x00, 0xAA, 0x80, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x2A, 0x80, 0x00, 0x2A, 0x80, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x2A, 0x00, 0x00, 0x0A, 0x80, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0xAA, 0x00, 0x00, 0x0A, 0xA0, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x0A, 0xAA, 0xA0, 0x00, 0x02, 0xA0, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x0A, 0xAA, 0x80, 0x00, 0x02, 0xA0, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x02, 0xAA, 0x80, 0x00, 0x0A, 0xA0, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0xAA, 0x00, 0x00, 0x0A, 0x80, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x28, 0x00, 0x00, 0x2A, 0x80, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0xAA, 0xA8, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x02, 0xAA, 0x80, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x2A, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0x0A, 0x02, 0xAA, 0xA0, 0x2A, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xA0, 0x28, 0x0A, 0x00, 0xAA, 0xAA, 0xAA, 0x02, 0x82, 0xAA, 0xA0, 0x28, 0x28, 0x20, 0x20, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xA0, 0x28, 0x0A, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x82, 0x80, 0xA0, 0x2A, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xA0, 0x28, 0x0A, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x02, 0x80, 0xA8, 0x08, 0x02, 0x80, 0x20, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xA0, 0x28, 0x0A, 0x00, 0xA0, 0x00, 0x00, 0x2A, 0x2A, 0x00, 0x2A, 0xAA, 0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0x00, 0xA0, 0x00, 0x00, 0x2A, 0x08, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0x00, 0xA0, 0x00, 0x00, 0x02, 0x0A, 0xAA, 0xA8, 0x0A, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x02, 0x80, 0xA0, 0x0A, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x02, 0x80, 0x28, 0x02, 0x00, 0x80, 0x00, 0x00, 0x02, 0x02, 0x80, 0xA0, 0x0A, 0x00, 0x00, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x02, 0x80, 0x28, 0x02, 0x02, 0x80, 0x00, 0x00, 0x02, 0x00, 0xA2, 0x80, 0x0A, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x02, 0x80, 0x28, 0x02, 0x02, 0x80, 0x00, 0x00, 0x02, 0xA8, 0x2A, 0x00, 0x0A, 0x00, 0x00, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x02, 0x80, 0x28, 0x0A, 0x0A, 0x80, 0x00, 0x00, 0x0A, 0xA0, 0xAA, 0x80, 0x0A, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x02, 0xAA, 0xAA, 0xAA, 0x0A, 0x00, 0x00, 0x00, 0x02, 0xAA, 0x82, 0xAA, 0xAA, 0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x0A, 0x2A, 0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x50,
  0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x50,
  0x55, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x55, 0x50,
  0x55, 0x54, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x55, 0x50,
  0x55, 0x55, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x85, 0x55, 0x50,
  0x55, 0x55, 0x50, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50
};

GUI_CONST_STORAGE GUI_BITMAP bmSys_default_xg = {
  94, // xSize
  94, // ySize
  24, // BytesPerLine
  2, // BitsPerPixel
  _acSys_default_xg,  // Pointer to picture data (indices)
  &_PalSys_default_xg   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmSys_default = {
  94, // xSize
  94, // ySize
  24, // BytesPerLine
  2, // BitsPerPixel
  _acSys_default_xg,  // Pointer to picture data (indices)
  &_PalSys_default   // Pointer to palette
};


/*************************** End of file ****************************/
