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
* Source file: file_return_xg                                        *
* Dimensions:  74 * 52                                               *
* NumColors:   3                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmfile_return_xg;
extern GUI_CONST_STORAGE GUI_BITMAP bmfile_return;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorsfile_return_xg[] = {
  0xA68524, 0x9C7300, 0xEAE2CA
};

static GUI_CONST_STORAGE GUI_COLOR _Colorsfile_return[] = {
  GUI_BUTTON_PRESS, 0x9C7300, 0xEAE2CA
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palfile_return_xg = {
  3,  // Number of entries
  0,  // No transparency
  &_Colorsfile_return_xg[0]
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palfile_return = {
  3,  // Number of entries
  0,  // No transparency
  &_Colorsfile_return[0]
};

static GUI_CONST_STORAGE unsigned char _acfile_return_xg[] = {
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x52, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA8, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x85, 0x55, 0x50,
  0x55, 0x54, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x55, 0x50,
  0x55, 0x56, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x55, 0x50,
  0x55, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x55, 0x50,
  0x55, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x50,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x0A, 0xAA, 0xA0, 0x2A, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x82, 0xAA, 0xAA, 0xA0, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0xA2, 0xA0, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0xA2, 0x80, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x02, 0xAA, 0xAA, 0x80, 0xA0, 0x2A, 0xAA, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x02, 0xAA, 0xAA, 0xA0, 0xA0, 0xAA, 0xAA, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x2A, 0x82, 0x80, 0x00, 0xA0, 0xA0, 0xA0, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x82, 0xAA, 0x02, 0x80, 0xA0, 0xA0, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x82, 0x8A, 0x8A, 0x80, 0xA0, 0xA0, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x82, 0x82, 0xAA, 0x00, 0xA0, 0xA0, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x82, 0x80, 0xAA, 0x00, 0xA0, 0xAA, 0xAA, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x8A, 0x02, 0xAA, 0x80, 0xA0, 0xAA, 0xAA, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x8A, 0x2A, 0x82, 0xA0, 0xA0, 0x20, 0x02, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x02, 0x88, 0xA8, 0x00, 0xA0, 0xA0, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x0A, 0xA8, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x28, 0x2A, 0xAA, 0xAA, 0xA8, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x02, 0xAA, 0xAA, 0xA0, 0xA0, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x50,
  0x55, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x50,
  0x55, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x15, 0x50,
  0x55, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x55, 0x50,
  0x55, 0x56, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x55, 0x50,
  0x55, 0x54, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x55, 0x50,
  0x55, 0x55, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x85, 0x55, 0x50,
  0x55, 0x55, 0x52, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x15, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50,
  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50
};

GUI_CONST_STORAGE GUI_BITMAP bmfile_return_xg = {
  74, // xSize
  52, // ySize
  19, // BytesPerLine
  2, // BitsPerPixel
  _acfile_return_xg,  // Pointer to picture data (indices)
  &_Palfile_return_xg   // Pointer to palette
};

GUI_CONST_STORAGE GUI_BITMAP bmfile_return = {
  74, // xSize
  52, // ySize
  19, // BytesPerLine
  2, // BitsPerPixel
  _acfile_return_xg,  // Pointer to picture data (indices)
  &_Palfile_return   // Pointer to palette
};

/*************************** End of file ****************************/
