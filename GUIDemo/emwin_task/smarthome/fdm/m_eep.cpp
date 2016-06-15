/*======================================================================  
maker  :jiaxing.shen
date   :2014.12.10
email  :55954781@qq.com
======================================================================*/
#include "m_include.h"
#include "m_nvic.h"
#include "m_eep.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_hal_flash.h"
//
//======================================================================
// 写入
//======================================================================
void c_eep::wirte(uint8 *source, uint32 tarAddr, uint16 len) {
    
    uint32_t FirstSector = 0, NbOfSectors = 0;
    uint32_t Address = 0, SECTORError = 0;
    __IO uint32_t data32 = 0 , MemoryProgramStatus = 0;
    
    
    FLASH_EraseInitTypeDef EraseInitStruct;
//
//------------------------------------
// 0. 关闭系统中断
    nvic.globalDisable();
//
//------------------------------------
// 1. 开启内部高速时钟
//    RCC->CR |= ((uint32_t)RCC_CR_HSION);
//    while((RCC->CR & RCC_CR_HSIRDY) == 0);
//
//------------------------------------
// 2. 解锁
	HAL_FLASH_Unlock();
//
//------------------------------------
// 3. 擦除并写入数据
    /* Get the 1st sector to erase */
    FirstSector = GetSector(tarAddr);
    /* Get the number of sector to erase from 1st sector*/
    NbOfSectors = 1;
    /* Fill EraseInit structure*/
    EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
    EraseInitStruct.Sector        = FirstSector;
    EraseInitStruct.NbSectors     = NbOfSectors;
    
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
    {
        while (1)
        {
            /* Make LED1 blink (100ms on, 2s off) to indicate error in Erase operation */
            BSP_LED_On(LED1);
            HAL_Delay(100);
            BSP_LED_Off(LED1);
            HAL_Delay(2000);
        }   
    }
    
    Address = tarAddr;

    //while (Address < tarAddr)
    for(int i=0; i<len; i++)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, Address, *source) == HAL_OK)
        {
            Address = Address + 1;
            source++;
        }
        else
        {
            /* Error occurred while writing data in Flash memory.
            User can add here some code to deal with this error */
            while (1)
            {
                /* Make LED1 blink (100ms on, 2s off) to indicate error in Write operation */
                BSP_LED_On(LED1);
                HAL_Delay(100);
                BSP_LED_Off(LED1);
                HAL_Delay(2000);
            }
        }
    }
  
//    EraseSector(tarAddr);
//    ProgramPage(tarAddr, len, source);
//
//------------------------------------
// 4. 锁定
	HAL_FLASH_Lock();
//
//------------------------------------
// 5. 关闭内部高速时钟
    //RCC->CR &= ~((uint32_t)RCC_CR_HSION);
   // while(RCC->CR & RCC_CR_HSIRDY);
//
//------------------------------------
// 6. 开启中断
    nvic.globalEnable();
}
//
//======================================================================
// 初始化EEP 功能
//======================================================================
/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
int c_eep::Init () {
    HAL_FLASH_Lock();
}
//
//======================================================================
// 结束解锁
//======================================================================
/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */
int c_eep::UnInit () {
    HAL_FLASH_Unlock();
}
//
//======================================================================
// 扇区擦除
//======================================================================
/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */
int c_eep::EraseSector (unsigned long adr) {
    FLASH_Erase_Sector(adr,FLASH_VOLTAGE_RANGE_1);//?
}
//
//======================================================================
// 页编程
//======================================================================
/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
*/
int c_eep::ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {
}



/**
  * @brief  Gets the sector of a given address
  * @param  None
  * @retval The sector of a given address
  */
int c_eep::GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_7) */
  {
    sector = FLASH_SECTOR_7;
  }
  return sector;
}

//
//======================================================================
c_eep   eep;
//
//======================================================================





