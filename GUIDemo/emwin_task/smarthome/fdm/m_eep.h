/*======================================================================  
maker  :jiaxing.shen
date   :2014.12.10
email  :55954781@qq.com
======================================================================*/
#ifndef __M_EEP_H__
#define __M_EEP_H__
//======================================================================
#include "typeDefine.h"
#include "stdint.h"
//======================================================================
//
// FLASH BANK size
#define BANK1_SIZE      0x00080000      // Bank1 Size = 512kB

#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base address of Sector 0, 32 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08008000) /* Base address of Sector 1, 32 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08010000) /* Base address of Sector 2, 32 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08018000) /* Base address of Sector 3, 32 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08020000) /* Base address of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08040000) /* Base address of Sector 5, 256 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08070000) /* Base address of Sector 6, 256 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x080A0000) /* Base address of Sector 7, 256 Kbytes */
//======================================================================
class c_eep {
public:
	void wirte (uint8 *source, uint32 tarAddr, uint16 len);
private:
    int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf);
    int EraseSector (unsigned long adr);
    int Init        ();
    int UnInit      ();
    int GetSector(uint32_t Address);
};
extern c_eep   eep;
//======================================================================
#endif 
//======================================================================

