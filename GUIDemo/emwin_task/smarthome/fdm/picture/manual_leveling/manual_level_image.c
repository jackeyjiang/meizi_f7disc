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
* Source file: manual_level_image                                    *
* Dimensions:  190 * 60                                              *
* NumColors:   4                                                     *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmmanual_level_image;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorsmanual_level_image[] = {
  0x7C6B1F, 0x95761C, 0xA48628, 0xEEE9DF
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palmanual_level_image = {
  4,  // Number of entries
  0,  // No transparency
  &_Colorsmanual_level_image[0]
};

static GUI_CONST_STORAGE unsigned char _acmanual_level_image[] = {
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0xAA, 0x9A, 0x6A, 0xAA, 0xAA, 0xA9, 0x99, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0x66, 0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0x6A, 0xA6, 0x6A, 0xAA, 0xAA, 0xAA, 0x9A, 0x56, 0x6A, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xA9, 0xBE, 0xAA, 0xAA, 0xAA, 0xAB, 0xAA, 0xAA, 0xAA, 0xAA, 0xBE, 0xAA, 0xAB, 0xEA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0x97, 0xE9, 0xAA, 0xAA, 0xAA, 0xAA, 0x9B, 0xEA, 0x9B, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 0x7F, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0xBE, 0xAA, 0xA5, 0xBE, 0xAA, 0x9A, 0x6A, 0x5F, 0xEA, 0xAA, 0xAA, 0xA5, 0xBE, 0x9A, 0x9F, 0xEA, 0xAA, 0x5A, 0xAA, 0x5B, 0xEA, 0xAA, 0xA6, 0x97, 0xEA, 0x6A, 0xAA, 0xAA, 0xAA, 0x97, 0xEA, 0x57, 0xFA, 0xAA, 0xAA, 0xA6, 0xA9, 0x7F, 0xAA, 0xAA, 0xAA, 
        0x9A, 0xAA, 0xAB, 0xFF, 0xFA, 0xA0,
  0xA5, 0xBF, 0xAF, 0xFF, 0xFF, 0xFF, 0xF6, 0xA9, 0x5F, 0xAA, 0xAA, 0xAA, 0xA5, 0xBD, 0xA6, 0x53, 0xFA, 0xAA, 0x6A, 0xAA, 0x5B, 0xEA, 0x9A, 0xA9, 0x97, 0xEA, 0x6F, 0xFF, 0xFE, 0xAA, 0x5B, 0xEA, 0xAB, 0xFA, 0xAA, 0xAA, 0x6A, 0xA9, 0x7F, 0xAA, 0xAA, 0xA7, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0xA0,
  0xA9, 0x2F, 0xEF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE5, 0xBE, 0xAF, 0xFF, 0xFF, 0xFF, 0x57, 0xEA, 0x5B, 0xE9, 0x5B, 0xEA, 0x57, 0xE5, 0x6F, 0xFF, 0xFE, 0x9A, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0xA6, 0xA5, 0x7F, 0xA6, 0xAA, 0x97, 
        0xFF, 0xFF, 0xFF, 0xFE, 0xAA, 0xA0,
  0xA9, 0x5B, 0xF1, 0x54, 0xBD, 0x05, 0x57, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0xFE, 0xBF, 0xFF, 0xFF, 0xFF, 0x57, 0xEA, 0x5B, 0xEA, 0x5B, 0xE6, 0xAB, 0xFA, 0xAF, 0x10, 0xFE, 0xA9, 0x4F, 0xBF, 0xFF, 0xFF, 0xFF, 0xEA, 0x6F, 0xA9, 0x3F, 0xAA, 0xAA, 0x93, 
        0xFA, 0xA5, 0x55, 0x55, 0xAA, 0xA0,
  0x69, 0x53, 0xD7, 0xFF, 0xFF, 0xFF, 0xD5, 0x44, 0xBE, 0x15, 0x05, 0x05, 0x6F, 0xFF, 0xEB, 0xFA, 0xAB, 0xFA, 0x87, 0xE6, 0x5B, 0xEA, 0x5B, 0xD5, 0xFF, 0xFF, 0xEF, 0x54, 0xFE, 0xA9, 0x6F, 0x57, 0xFF, 0xFF, 0xF9, 0xA9, 0x5F, 0x95, 0x7F, 0xAA, 0xAA, 0x97, 
        0xF5, 0x99, 0x69, 0xAA, 0x66, 0xA0,
  0xAA, 0x56, 0x57, 0xFF, 0xFF, 0xFF, 0xD6, 0x54, 0xFD, 0x96, 0xF9, 0x99, 0x6F, 0xFF, 0xE6, 0xFA, 0x4F, 0xEA, 0x57, 0xEA, 0x5B, 0xEA, 0x5B, 0xD5, 0xFF, 0xFF, 0xAF, 0x94, 0xFE, 0xA9, 0x3F, 0x57, 0xFF, 0xFF, 0xFE, 0xA9, 0x5F, 0xA9, 0x3F, 0xAA, 0x9A, 0x97, 
        0xF9, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA6, 0x6A, 0x55, 0x54, 0xBD, 0x56, 0xAA, 0x97, 0xFA, 0x96, 0xF6, 0xA6, 0x54, 0xBD, 0x54, 0xFE, 0x6F, 0xEA, 0x53, 0xEA, 0x5B, 0xEA, 0x5B, 0xD5, 0x47, 0xE5, 0x6F, 0xA5, 0xFE, 0xA9, 0xBF, 0x87, 0xEA, 0xAA, 0xFD, 0xA9, 0x5F, 0xA9, 0x7F, 0xFF, 0xFE, 0x53, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA0,
  0x9B, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFA, 0x5B, 0xFA, 0x96, 0xFA, 0xAA, 0x55, 0xBE, 0x95, 0xBF, 0xFF, 0xAA, 0x57, 0xEA, 0x5B, 0xEA, 0x5B, 0xEA, 0x4B, 0xE9, 0x6F, 0x55, 0xFE, 0x95, 0xFF, 0x57, 0xEA, 0xAA, 0xFE, 0xA9, 0x5F, 0xA9, 0x3F, 0xFF, 0xFE, 0x97, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA0,
  0x53, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xF9, 0x4F, 0xEA, 0x96, 0xFA, 0x9A, 0x65, 0xBD, 0xA5, 0x2F, 0xFE, 0xAA, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0x4F, 0xFD, 0x6F, 0x95, 0xFE, 0xA6, 0xFF, 0x93, 0xFF, 0xFF, 0xFE, 0x99, 0x5F, 0xA5, 0x7F, 0x55, 0x5A, 0x97, 
        0xF1, 0x55, 0x55, 0x55, 0x5A, 0xA0,
  0x50, 0x0F, 0x95, 0x55, 0x55, 0x51, 0x6A, 0x7F, 0x9A, 0xAB, 0xFA, 0xAA, 0xA4, 0xBF, 0xE9, 0x7F, 0xFF, 0x9A, 0x53, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0x6F, 0xFF, 0x2F, 0x95, 0xFE, 0x93, 0xFF, 0x53, 0xEA, 0xAA, 0xFD, 0xA5, 0x5F, 0xA5, 0x7F, 0x55, 0x6A, 0x97, 
        0xF9, 0x95, 0x55, 0x56, 0x6A, 0xA0,
  0xA9, 0x1F, 0xA7, 0xFF, 0xFF, 0xFF, 0x99, 0xBF, 0x9F, 0xFF, 0xFF, 0xFF, 0xAB, 0xFF, 0xEB, 0xFF, 0xFF, 0xFE, 0x94, 0x15, 0x4B, 0xC5, 0x4B, 0xE9, 0x7F, 0xFF, 0xEF, 0x95, 0xFE, 0x8B, 0xEF, 0xBF, 0xFF, 0xFF, 0xFF, 0xEA, 0x5F, 0xA5, 0x7F, 0xAA, 0xAA, 0x97, 
        0xFA, 0xA9, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x5F, 0x93, 0xFF, 0xFF, 0xFF, 0xA6, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x6F, 0xFF, 0xFF, 0xF8, 0x6F, 0xFF, 0xA5, 0x59, 0x5B, 0xD6, 0x55, 0xA5, 0xBF, 0xEB, 0xAF, 0xA5, 0xFE, 0x57, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE5, 0x5F, 0xA5, 0x7F, 0xAA, 0xAA, 0x97, 
        0xF7, 0xFF, 0xFF, 0xFF, 0xEA, 0xA0,
  0xAA, 0x5F, 0x97, 0xF5, 0x54, 0x4F, 0x9B, 0xFF, 0x95, 0x52, 0xF5, 0x59, 0x4F, 0xFD, 0xBF, 0xF9, 0x4B, 0xFF, 0x5F, 0xE9, 0x5B, 0xE6, 0x97, 0xF5, 0xFF, 0xE6, 0x2F, 0x94, 0xFE, 0x56, 0x2F, 0xFE, 0xAA, 0xAA, 0xAB, 0xE9, 0x5F, 0xA5, 0x7F, 0xAA, 0xAA, 0x57, 
        0xF3, 0xFF, 0xFF, 0xFF, 0xEA, 0xA0,
  0x95, 0x5F, 0x97, 0xFF, 0xFF, 0xFF, 0x9B, 0xEF, 0xAA, 0x96, 0xF6, 0x69, 0x58, 0xBD, 0x62, 0xFA, 0x5F, 0xD5, 0x5F, 0xEA, 0x4B, 0xEA, 0x97, 0xF6, 0xFB, 0xE5, 0x7F, 0x94, 0xFE, 0x99, 0x6F, 0xFA, 0xAA, 0xAA, 0xAB, 0xE9, 0x5F, 0xA9, 0x7F, 0xAA, 0xAA, 0x53, 
        0xF7, 0xFA, 0xAA, 0xAB, 0xEA, 0xA0,
  0xA9, 0x5F, 0x93, 0xFF, 0xFF, 0xFF, 0x83, 0xDF, 0xAA, 0x56, 0xFA, 0xA9, 0x94, 0xBD, 0x96, 0xFA, 0x5F, 0xDA, 0x5F, 0xEA, 0x5B, 0xEA, 0x53, 0xF4, 0xF7, 0xE5, 0x7F, 0x94, 0xFD, 0xBD, 0x6F, 0xAB, 0xFF, 0xFF, 0xFE, 0xA9, 0x5F, 0xA9, 0x7F, 0xAA, 0xAA, 0x53, 
        0xE7, 0xF5, 0x55, 0x53, 0xEA, 0xA0,
  0xA9, 0x5F, 0x9B, 0xFA, 0xAA, 0xAF, 0x99, 0x5F, 0xA6, 0xA2, 0xF6, 0xAA, 0xA5, 0xBE, 0x93, 0xF5, 0x5F, 0xEA, 0x4F, 0xEA, 0x5B, 0xEA, 0x93, 0xF5, 0xD7, 0xE9, 0x3E, 0x94, 0xFD, 0xFD, 0x6F, 0x5B, 0xFF, 0xFF, 0xFD, 0xA9, 0x4F, 0xA9, 0x7F, 0xAA, 0xAA, 0x57, 
        0xE7, 0xF6, 0xAA, 0x57, 0xEA, 0xA0,
  0xA9, 0x5F, 0xBF, 0xFF, 0xFF, 0xFF, 0xA5, 0x5F, 0xAA, 0x96, 0xFA, 0xAA, 0x95, 0xBE, 0x97, 0xF9, 0x5F, 0xE9, 0x5F, 0xEA, 0x4B, 0xEA, 0x93, 0xF5, 0x57, 0xE5, 0xBE, 0x94, 0xFC, 0xFD, 0x6F, 0x55, 0x54, 0xFD, 0x5A, 0x99, 0x5F, 0xA9, 0x3F, 0xAA, 0xAA, 0x5B, 
        0xD7, 0xFA, 0xAA, 0x57, 0xEA, 0xA0,
  0xA9, 0x4F, 0xFF, 0xFF, 0xFF, 0xFF, 0x99, 0x5F, 0xAA, 0x96, 0xF9, 0xAA, 0xA5, 0xBE, 0x5B, 0xEA, 0x5F, 0xE9, 0x5F, 0xDA, 0x4B, 0xEA, 0x93, 0xFA, 0x97, 0xE5, 0xFE, 0xA4, 0xFC, 0xFE, 0x6F, 0x9A, 0x94, 0xFE, 0xAA, 0xAA, 0xAF, 0xEA, 0xBF, 0xAA, 0xAA, 0x8F, 
        0xD7, 0xFA, 0xAA, 0x53, 0xEA, 0xA0,
  0xA9, 0x6F, 0xFB, 0xF5, 0x55, 0x5F, 0xAA, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE4, 0xFE, 0x6F, 0xEA, 0x5F, 0xEA, 0x5F, 0xEA, 0xAF, 0xEA, 0xAB, 0xFA, 0x97, 0xE6, 0xFA, 0x94, 0xFF, 0xF9, 0x6F, 0x6A, 0x96, 0xFE, 0xAA, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 
        0x97, 0xFF, 0xFF, 0xFF, 0xEA, 0xA0,
  0xA9, 0x6F, 0xE3, 0xFA, 0x6F, 0xFF, 0xA9, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD, 0xFF, 0xA9, 0x4F, 0xE9, 0x4F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x97, 0xEB, 0xF6, 0xA4, 0xFF, 0xF9, 0x6F, 0xA9, 0xFF, 0xFE, 0x69, 0x4F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
        0x53, 0xFF, 0xFF, 0xFF, 0xEA, 0xA0,
  0xA9, 0x5F, 0x57, 0xFA, 0x6F, 0xFF, 0xAA, 0x4F, 0x95, 0x11, 0x00, 0x55, 0x5F, 0xFA, 0xFE, 0xA9, 0x4F, 0xEA, 0x5B, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x97, 0xEF, 0xEA, 0xA5, 0x7F, 0xE5, 0x2F, 0x95, 0xBF, 0xFA, 0xA9, 0x54, 0x51, 0x55, 0x54, 0x54, 0x51, 0x7E, 
        0x93, 0xFA, 0xAA, 0xAB, 0xEA, 0xA0,
  0xA9, 0x59, 0x96, 0xE9, 0x4F, 0xE9, 0xA9, 0x5F, 0x95, 0x55, 0x59, 0x69, 0x5A, 0xA1, 0xFA, 0xAA, 0x5B, 0xEA, 0x95, 0x55, 0x55, 0x55, 0x42, 0xEA, 0x96, 0xE3, 0xAA, 0x95, 0x45, 0x69, 0x6F, 0xA5, 0x6A, 0xAA, 0xAA, 0x56, 0x95, 0x55, 0x95, 0x95, 0x55, 0x6E, 
        0x56, 0xE5, 0x55, 0x57, 0xEA, 0xA0,
  0xAA, 0x5A, 0x56, 0xA9, 0x55, 0x5A, 0xAA, 0x56, 0xAA, 0xAA, 0x9A, 0xA6, 0x55, 0x95, 0x5A, 0xA9, 0x56, 0x6A, 0xAA, 0x9A, 0xAA, 0x69, 0x95, 0xAA, 0x95, 0x55, 0xAA, 0xA6, 0x9A, 0xA9, 0x56, 0xA9, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0x9A, 0x5A, 
        0x55, 0x6A, 0xAA, 0x55, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xA6, 0xA6, 0xAA, 0xA9, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0x65, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0x9A, 0xAA, 0xA9, 0xA6, 0xA9, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 
        0x99, 0xAA, 0x9A, 0x9A, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x6A, 0xAA, 0x9A, 0xA6, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0xAA, 0xAA, 0xBF, 0xA6, 0xFA, 0xAA, 0xA5, 0xFA, 0xAA, 0xAA, 0xAA, 0x69, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 0x69, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0x5F, 0xE9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xF9, 0xBF, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA6, 0xBE, 0xA9, 0x7F, 0x96, 0xF6, 0xAA, 0x97, 0xFA, 0xAA, 0xAA, 0xAA, 0x97, 0xF9, 0x7F, 0xFF, 0xFF, 0xFE, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x5F, 0xE5, 0xFF, 0xFF, 0xFF, 0x6A, 0x97, 0xF5, 0xBE, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA5, 0x7F, 0x99, 0x3F, 0x56, 0xFA, 0xAA, 0x9B, 0xF5, 0xFF, 0xFF, 0xFF, 0x56, 0xFD, 0x7F, 0xFF, 0xFF, 0xFE, 0x4F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x5F, 0xE5, 0xFF, 0xFF, 0xFF, 0xAA, 0x5B, 0xE5, 0xFE, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA5, 0x2F, 0xE9, 0x7F, 0x96, 0xFA, 0xAA, 0x6F, 0xD5, 0xFF, 0xFF, 0xFF, 0x94, 0xFF, 0x3E, 0xAB, 0xEA, 0xBE, 0x54, 0x05, 0x43, 0xD5, 0x51, 0x5A, 0x4F, 0xD5, 0xFC, 0x45, 0x3F, 0xAA, 0x5B, 0xD4, 0xFE, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x69, 0x5B, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0xBF, 0xA5, 0x55, 0x55, 0x5A, 0x95, 0x3F, 0x3D, 0x57, 0xD8, 0x7E, 0x56, 0xE6, 0x57, 0xD6, 0x5B, 0xA9, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xA6, 0x4F, 0xE6, 0xFF, 0xFF, 0xFF, 0xF9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x47, 0xEF, 0xFF, 0xFF, 0xFF, 0xD6, 0xFE, 0xA5, 0xAA, 0xAA, 0xAA, 0x69, 0x5D, 0x7E, 0xAB, 0xEA, 0xBE, 0x57, 0xFA, 0x53, 0xD9, 0x5F, 0xE4, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xA9, 0x6F, 0x93, 0xFF, 0xFF, 0xFF, 0xE9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0x55, 0x54, 0x3F, 0x42, 0xF5, 0x5B, 0xF9, 0xFE, 0xAA, 0xAA, 0xAA, 0xA6, 0x55, 0x7D, 0xFF, 0xFF, 0xBE, 0x96, 0xFE, 0x47, 0xE5, 0x7F, 0x95, 0xAF, 0xE9, 0xBE, 0xAA, 0xBF, 0xA9, 0x3F, 0x5B, 0xE3, 0xE5, 0x55, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x66, 0x95, 0x7F, 0x52, 0xFA, 0x57, 0xE6, 0xF9, 0x6A, 0xAA, 0xAA, 0xAF, 0xF5, 0x7D, 0xAB, 0xEA, 0xBE, 0x94, 0xBF, 0x83, 0xE9, 0xBF, 0xA5, 0x5F, 0xD7, 0xFF, 0xEB, 0xFF, 0xE5, 0xBF, 0x4F, 0xD7, 0xE5, 0x96, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA6, 0xFF, 0xA9, 0x7F, 0x96, 0xFA, 0x96, 0x9B, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x7E, 0x57, 0xD4, 0x7E, 0x94, 0x3F, 0x97, 0xD6, 0xFE, 0xAA, 0x4F, 0xD7, 0xFF, 0xEB, 0xFF, 0xE5, 0xFF, 0x7F, 0x97, 0xEA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x96, 0xFF, 0xA9, 0x3F, 0x96, 0xF6, 0x69, 0x5F, 0xEB, 0xFF, 0xFF, 0xFF, 0xE1, 0xF4, 0x7F, 0xFF, 0xFF, 0xFE, 0xA5, 0x6F, 0xD7, 0xDB, 0xFA, 0x6A, 0x5F, 0xEB, 0xD7, 0xEB, 0xC3, 0xD6, 0xFF, 0x7F, 0x93, 0xFF, 0xFF, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x95, 0x4F, 0xAF, 0xFF, 0xFF, 0xFF, 0xFA, 0x7F, 0x9B, 0xFF, 0xFF, 0xFF, 0xE0, 0xF5, 0x3F, 0xFF, 0xFF, 0xFE, 0x99, 0x4B, 0xE3, 0xDB, 0xEA, 0xAA, 0x5F, 0xFF, 0xD7, 0xEB, 0xD7, 0xD3, 0xFF, 0x2E, 0x57, 0xFF, 0xFF, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA5, 0x5F, 0xBF, 0xFF, 0xFF, 0xFF, 0xF5, 0xFF, 0x95, 0x55, 0x0B, 0xD5, 0x95, 0xF5, 0x3C, 0x55, 0x55, 0x7E, 0xA9, 0x57, 0x97, 0xD6, 0xAA, 0xA5, 0xBF, 0xFF, 0xFF, 0xEB, 0xFF, 0xDB, 0xEF, 0x5A, 0x93, 0xE5, 0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x5F, 0xAA, 0xBF, 0xAB, 0xFA, 0xA6, 0xFF, 0xAA, 0x5A, 0x5B, 0xDA, 0x95, 0xF5, 0x7E, 0xBF, 0xFE, 0x7E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xFF, 0xEB, 0xFF, 0xD7, 0xCF, 0xAA, 0x93, 0xE6, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x4F, 0x95, 0xBE, 0x52, 0xF5, 0x5B, 0xFF, 0xA9, 0xA9, 0x5B, 0xEA, 0x91, 0xF5, 0x3D, 0xFF, 0xFF, 0x7E, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xD6, 0x92, 0xBE, 0x96, 0x96, 0x1F, 0xAA, 0x97, 0xE9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x5F, 0xA4, 0xFD, 0x56, 0xFA, 0x5B, 0xEF, 0xA9, 0xAA, 0x5B, 0xEA, 0x94, 0xF7, 0xFD, 0xF9, 0x2F, 0x7E, 0x6A, 0xAA, 0xAB, 0xEA, 0xAA, 0xAA, 0x0F, 0xDA, 0xAA, 0xBE, 0xAA, 0xA9, 0x5F, 0xAA, 0x97, 0xEA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x5F, 0xA6, 0xFE, 0x96, 0xFA, 0x56, 0x9F, 0xA6, 0xAA, 0x5B, 0xEA, 0xA4, 0xFF, 0xFC, 0xF9, 0x6F, 0x7E, 0x95, 0x55, 0x53, 0xD5, 0x55, 0x99, 0x5F, 0xDF, 0xFF, 0xFF, 0xFF, 0xF9, 0x4F, 0xA9, 0x53, 0xFF, 0xFF, 0xEA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x5F, 0x9B, 0xFA, 0x96, 0xF9, 0x96, 0x5F, 0xAA, 0xA9, 0x5B, 0xE9, 0xA2, 0xFF, 0xFD, 0xFE, 0xBF, 0x7E, 0xAA, 0xA9, 0x53, 0xEA, 0x6A, 0x6A, 0x4F, 0xDA, 0xAB, 0xFF, 0xEA, 0xA9, 0x5F, 0xA6, 0x87, 0xFF, 0xFF, 0xE6, 0xFF, 0x6A, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0x6F, 0xAF, 0xEA, 0x62, 0xFA, 0xA5, 0x5F, 0xAA, 0xAA, 0x5B, 0xEA, 0x93, 0xFD, 0xF8, 0xFF, 0xFF, 0x7E, 0xAA, 0xAA, 0x53, 0xEA, 0xAA, 0xAA, 0x4F, 0xD5, 0x6F, 0xFF, 0xE5, 0xAA, 0x5F, 0xAA, 0x53, 0xE5, 0x55, 0xA7, 0xFF, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA5, 0xBF, 0xEF, 0xEA, 0x92, 0xFA, 0xAA, 0x5F, 0xAA, 0xA6, 0x4B, 0xEA, 0x92, 0xF2, 0xF5, 0xFF, 0xFE, 0x7E, 0xAA, 0xAA, 0x97, 0xEA, 0xAA, 0xAA, 0x5F, 0xE5, 0xFF, 0x7E, 0xFE, 0x99, 0x5F, 0xAA, 0x57, 0xE6, 0x5A, 0x93, 0xEB, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA6, 0xFF, 0xFF, 0xAA, 0x96, 0xAA, 0xAA, 0x5F, 0xAA, 0xAA, 0xAF, 0xEA, 0x94, 0x97, 0xF4, 0xB9, 0x54, 0xBE, 0x9A, 0xAA, 0x57, 0xEA, 0xAA, 0x99, 0x4F, 0xEF, 0xFC, 0x7D, 0xBF, 0xF9, 0x5F, 0xAA, 0x93, 0xEA, 0xAA, 0x97, 0xEB, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x97, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x4F, 0xA9, 0x6F, 0xFF, 0xEA, 0xA9, 0x5F, 0xE5, 0x55, 0xBF, 0xFE, 0xAA, 0xAA, 0x53, 0xEA, 0xAA, 0xA6, 0xFF, 0xFF, 0xE5, 0x7D, 0x5F, 0xF9, 0x5F, 0xAA, 0x53, 0xE6, 0xAA, 0x57, 0xFF, 0xEA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x95, 0xE5, 0x2F, 0xFF, 0xFF, 0xFF, 0xFA, 0x5F, 0xA9, 0x6F, 0xFF, 0xAA, 0xAA, 0x5F, 0xAA, 0xA5, 0xBF, 0xFD, 0xAA, 0xAA, 0x53, 0xEA, 0xAA, 0xA6, 0xFF, 0xAE, 0x69, 0x7D, 0x52, 0xF9, 0x4F, 0xAA, 0x57, 0xEA, 0xAA, 0x56, 0xFF, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x55, 0xA5, 0x51, 0x55, 0x55, 0x55, 0x6A, 0x5A, 0xA9, 0x55, 0x5A, 0xAA, 0xAA, 0x5A, 0xAA, 0x95, 0x6A, 0xAA, 0xAA, 0xAA, 0x97, 0xEA, 0xAA, 0x94, 0xA9, 0x5A, 0xA5, 0x7E, 0x55, 0x59, 0x5F, 0xA6, 0x57, 0xEA, 0xAA, 0xA5, 0x56, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xA9, 0xAA, 0x55, 0x55, 0x65, 0x66, 0xA9, 0x9A, 0xA9, 0x66, 0x6A, 0x6A, 0xAA, 0x5A, 0xAA, 0x99, 0x55, 0xAA, 0x6A, 0xAA, 0x95, 0xAA, 0xAA, 0x95, 0x5A, 0x66, 0xA9, 0x5A, 0xA9, 0xA9, 0x59, 0xAA, 0x66, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xA5, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xAA, 0x99, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xA9, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA6, 0xAA, 0xA6, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
        0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0
};

GUI_CONST_STORAGE GUI_BITMAP bmmanual_level_image = {
  190, // xSize
  60, // ySize
  48, // BytesPerLine
  2, // BitsPerPixel
  _acmanual_level_image,  // Pointer to picture data (indices)
  &_Palmanual_level_image   // Pointer to palette
};

/*************************** End of file ****************************/
