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
* Source file: manual_e_inc_xg                                       *
* Dimensions:  63 * 63                                               *
* NumColors:   3                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorsmanual_e_inc_xg[] = {
  0xA48422, 0x9B7301, 0xF8F6EF
};

static GUI_CONST_STORAGE GUI_COLOR _Colorsmanual_e_inc[] = {
  GUI_DARKBLUE, 0x9B7301, 0xF8F6EF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palmanual_e_inc_xg = {
  3,  // Number of entries
  0,  // No transparency
  &_Colorsmanual_e_inc_xg[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palmanual_e_inc = {
  3,  // Number of entries
  0,  // No transparency
  &_Colorsmanual_e_inc[0]
};

static GUI_CONST_STORAGE unsigned char _acmanual_e_inc_xg[] = {
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x0A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x81, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x52, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x15, 0x55, 0x54,
  0x55, 0x55, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x55, 0x54,
  0x55, 0x54, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x55, 0x54,
  0x55, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x54,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x54,
  0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x54,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x54,
  0x54, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x54,
  0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x54,
  0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14,
  0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0x80, 0x12, 0xAA, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xA0, 0x04, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xA0, 0x01, 0x2A, 0xAA, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x4A, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x5A, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x16, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0x80, 0x2A, 0xAA, 0xAA, 0xAA, 0xA8, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0x80, 0x0A, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x12, 0xAA, 0xAA, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x04, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x01, 0x2A, 0xAA, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xA0, 0x00, 0x4A, 0xAA, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xA0, 0x00, 0x12, 0xAA, 0x80, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x2A, 0xAA, 0xA0, 0x00, 0x04, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94,
  0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14,
  0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x14,
  0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x54,
  0x54, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x54,
  0x55, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x54,
  0x55, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x54,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x54,
  0x55, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x54,
  0x55, 0x54, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x55, 0x54,
  0x55, 0x55, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x55, 0x54,
  0x55, 0x55, 0x52, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x15, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x0A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x81, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54
};

GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc_xg = {
  63, // xSize
  63, // ySize
  16, // BytesPerLine
  2, // BitsPerPixel
  _acmanual_e_inc_xg,  // Pointer to picture data (indices)
  &_Palmanual_e_inc_xg   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmmanual_e_inc = {
  63, // xSize
  63, // ySize
  16, // BytesPerLine
  2, // BitsPerPixel
  _acmanual_e_inc_xg,  // Pointer to picture data (indices)
  &_Palmanual_e_inc   // Pointer to palette
};

/*************************** End of file ****************************/
