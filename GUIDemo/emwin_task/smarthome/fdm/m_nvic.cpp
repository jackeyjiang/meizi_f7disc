//===============================================
#include "m_include.h"
#include "m_nvic.h"
//===============================================
// 全局中断开启
//===============================================
void c_nvic::globalEnable() {
    asm volatile("cpsie i");
}

//===============================================
// 全局中断关闭
//===============================================
void c_nvic::globalDisable() {
    asm volatile("cpsid i");
}

//===============================================
// 开启中断
//===============================================
void c_nvic::irqEnable(IRQn irq_num, uint8 mPriority, uint8 sPriority) {
	uint32 tmpPriority = 0, tmpPre = 0, tmpSub = 0;
	
    if (irq_num < 0) {
        return;
    }
    HAL_NVIC_SetPriority(irq_num, 0x0F, 0x00);
    HAL_NVIC_EnableIRQ(irq_num);
}

//===============================================
// 开启中断
//===============================================
void c_nvic::irqEnable(IRQn_Type irq_num) {
    if (irq_num < 0) {
        return;
    }   
    HAL_NVIC_SetPriority(irq_num, 0x0F, 0x00);
    HAL_NVIC_EnableIRQ(irq_num);
}

//===============================================
// 开启中断,NOUSE
//===============================================
void c_nvic::priorityGroup(nvic_priority_Group group) {
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
}
//
//===============================================
// 关闭中断
//===============================================
void c_nvic::irqDisable(IRQn irq_num) {
    if (irq_num < 0) {
        return;
    }
    HAL_NVIC_DisableIRQ(irq_num);
}

c_nvic nvic;
