/*
 * @Descripttion: system config
 * @Author: Jerry
 * @Date: 2021-12-01 16:39:34
 * @LastEditTime: 2021-12-31 17:04:06
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

#define DEV_MAJOR_VER              0
#define DEV_MINOR_VER              1
#define GET_SOFTWARE_VER_NUM()     ((uint8_t)((DEV_MAJOR_VER << 4) | DEV_MINOR_VER))

#define GET_SOFTWARE_VER_STR()      _SW_VER_STR(DEV_MAJOR_VER, DEV_MINOR_VER)
#define _SW_VER_STR(major, minor)   __SW_VER_STR(major, minor)
#define __SW_VER_STR(major, minor)  "V" ## #major ## "." ## #minor

#define SYS_DEBUG_PRINTF_ENABLE    1

#endif
