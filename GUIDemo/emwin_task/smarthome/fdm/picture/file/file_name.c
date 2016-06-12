﻿/*********************************************************************
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
* Source file: file_name                                             *
* Dimensions:  25 * 25                                               *
* NumColors:   3                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmfile_name;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorsfile_name[] = {
  0x9A7302, 0xCDBD83, 0xBDA45A
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palfile_name = {
  3,  // Number of entries
  0,  // No transparency
  &_Colorsfile_name[0]
};

static GUI_CONST_STORAGE unsigned char _acfile_name[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x95, 0x55, 0x55, 0x00, 0x00,
  0x00, 0x00, 0x55, 0x55, 0x55, 0x80, 0x00,
  0x00, 0x09, 0x50, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x25, 0x50, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x95, 0x50, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x55, 0x50, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x80, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x01, 0x60, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x05, 0x58, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x29, 0x6A, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x01, 0x60, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x01, 0x60, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x02, 0x80, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x09, 0x80, 0x00,
  0x00, 0x5A, 0xAA, 0xAA, 0xA5, 0x80, 0x00,
  0x00, 0x95, 0x55, 0x55, 0x55, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

GUI_CONST_STORAGE GUI_BITMAP bmfile_name = {
  25, // xSize
  25, // ySize
  7, // BytesPerLine
  2, // BitsPerPixel
  _acfile_name,  // Pointer to picture data (indices)
  &_Palfile_name   // Pointer to palette
};

/*************************** End of file ****************************/
