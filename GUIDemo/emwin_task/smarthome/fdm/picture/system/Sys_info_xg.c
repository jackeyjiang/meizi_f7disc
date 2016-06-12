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
* Source file: Sys_info_xg                                           *
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

extern GUI_CONST_STORAGE GUI_BITMAP bmSys_info_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmSys_info;
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
static GUI_CONST_STORAGE GUI_COLOR _ColorsSys_info_xg[] = {
  0xA58523, 0xF3EFE1, 0x9C7300
};

static GUI_CONST_STORAGE GUI_COLOR _ColorsSys_info[] = {
  GUI_DARKBLUE, 0xF3EFE1, 0x9C7300
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalSys_info_xg = {
  3,  // Number of entries
  0,  // No transparency
  &_ColorsSys_info_xg[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalSys_info = {
  3,  // Number of entries
  0,  // No transparency
  &_ColorsSys_info[0]
};

static GUI_CONST_STORAGE unsigned char _acSys_info_xg[] = {
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0xAA, 0xAA, 0xA0,
  0xAA, 0xA9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x6A, 0xAA, 0xA0,
  0xAA, 0x85, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0xAA, 0xA0,
  0xAA, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xAA, 0xA0,
  0xAA, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xAA, 0xA0,
  0xA8, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xAA, 0xA0,
  0xA8, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x55, 0x54, 0x15, 0x55, 0x55, 0x50, 0x55, 0x55, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x50, 0x01, 0x55, 0x55, 0x00, 0x15, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x40, 0x01, 0x55, 0x55, 0x00, 0x05, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x40, 0x01, 0x55, 0x55, 0x00, 0x05, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x50, 0x01, 0x55, 0x55, 0x00, 0x15, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x55, 0x54, 0x05, 0x55, 0x55, 0x40, 0x55, 0x55, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x14, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x55, 0x54, 0x05, 0x55, 0x15, 0x54, 0x01, 0x40, 0x14, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x50, 0x14, 0x05, 0x01, 0x14, 0x14, 0x01, 0x55, 0x55, 0x55, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x05, 0x55, 0x50, 0x14, 0x05, 0x55, 0x15, 0x54, 0x05, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x50, 0x14, 0x05, 0x55, 0x15, 0x54, 0x05, 0x05, 0x55, 0x54, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x50, 0x14, 0x00, 0x00, 0x51, 0x40, 0x15, 0x05, 0x55, 0x50, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x01, 0x54, 0x50, 0x14, 0x05, 0x55, 0x55, 0x55, 0x15, 0x05, 0x55, 0x50, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x01, 0x55, 0x50, 0x14, 0x00, 0x15, 0x55, 0x00, 0x15, 0x05, 0x55, 0x54, 0x05, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x05, 0x50, 0x50, 0x14, 0x05, 0x54, 0x05, 0x55, 0x05, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x04, 0x50, 0x50, 0x14, 0x55, 0x55, 0x05, 0x55, 0x05, 0x05, 0x55, 0x54, 0x14, 0x05, 0x00, 0x40, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x50, 0x14, 0x45, 0x55, 0x15, 0x54, 0x05, 0x04, 0x00, 0x14, 0x11, 0x41, 0x40, 0x50, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x50, 0x40, 0x14, 0x45, 0x01, 0x14, 0x14, 0x05, 0x04, 0x00, 0x14, 0x51, 0x41, 0x45, 0x14, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x51, 0x40, 0x15, 0x45, 0x55, 0x15, 0x54, 0x05, 0x05, 0x55, 0x54, 0x51, 0x50, 0x15, 0x04, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x55, 0x00, 0x15, 0x05, 0x55, 0x15, 0x54, 0x05, 0x05, 0x55, 0x54, 0x00, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xA0,
  0xA8, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2A, 0xA0,
  0xAA, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xAA, 0xA0,
  0xAA, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xAA, 0xA0,
  0xAA, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0xAA, 0xA0,
  0xAA, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x4A, 0xAA, 0xA0,
  0xAA, 0xA8, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x2A, 0xAA, 0xA0,
  0xAA, 0xAA, 0x81, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x42, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0
};

GUI_CONST_STORAGE GUI_BITMAP bmSys_info_xg = {
  94, // xSize
  94, // ySize
  24, // BytesPerLine
  2, // BitsPerPixel
  _acSys_info_xg,  // Pointer to picture data (indices)
  &_PalSys_info_xg   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmSys_info = {
  94, // xSize
  94, // ySize
  24, // BytesPerLine
  2, // BitsPerPixel
  _acSys_info_xg,  // Pointer to picture data (indices)
  &_PalSys_info   // Pointer to palette
};

/*************************** End of file ****************************/