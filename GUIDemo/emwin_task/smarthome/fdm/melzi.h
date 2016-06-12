/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MELZI_H
#define __MELZI_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "sysConf.h"
     
int melzi_start(void);
int melzi_stop(void);
__task void initTask(void const *argument);
          
#ifdef __cplusplus
}
#endif

#endif