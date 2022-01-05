/*
 * @Descripttion: debug log
 * @Author: Jerry
 * @Date: 2021-12-07 13:40:37
 * @LastEditTime: 2021-12-28 11:22:35
 * 
 * reference url: https://blog.csdn.net/qq_42073370/article/details/82532291?utm_source=app
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _LOG_H__
#define _LOG_H__

#include <stdio.h>
#include "string.h"
#include "config.h"
 
//Change the row control log output level (that is, change LDG_LEVEL_DEBUG)
#define LOG_LEVEL           LOG_LEVEL_ALL
 
//Define levels
#define LOG_LEVEL_ALL       1   /*All*/
#define LOG_LEVEL_TRACE     2   /*Trace*/
#define LOG_LEVEL_DEBUG     3   /*Debug*/
#define LOG_LEVEL_INFO      4   /*INformation*/
#define LOG_LEVEL_WARN      5   /*Warning*/
#define LOG_LEVEL_ERROR     6   /*Error*/
#define LOG_LEVEL_FATAL     7   /*Fatal*/
#define LOG_LEVEL_SILENT    8   /*Silent*/ 
#define TITLE_ALL           "[A]"
#define TITLE_TRACE         "[T]"
#define TITLE_DEBUG         "[D]"
#define TITLE_INFO          "[I]"
#define TITLE_WARN          "[W]"
#define TITLE_ERROR         "[E]"
#define TITLE_FATAL         "[F]"
 
//Output info log prototypes at all levels
#define LOGA(format,...)    LOG_ALL(format,##__VA_ARGS__)
#define LOGT(format,...)    LOG_TRACE(format,##__VA_ARGS__)
#define LOGD(format,...)    LOG_DEBUG(format,##__VA_ARGS__)
#define LOGI(format,...)    LOG_INFO(format,##__VA_ARGS__)
#define LOGW(format,...)    LOG_WARN(format,##__VA_ARGS__)
#define LOGE(format,...)    LOG_ERROR(format,##__VA_ARGS__)
#define LOGF(format,...)    LOG_FATAL(format,##__VA_ARGS__)

//Output original log prototypes at all levels
#define OLOGA(format,...)    OLOG_ALL(format,##__VA_ARGS__)
#define OLOGT(format,...)    OLOG_TRACE(format,##__VA_ARGS__)
#define OLOGD(format,...)    OLOG_DEBUG(format,##__VA_ARGS__)
#define OLOGI(format,...)    OLOG_INFO(format,##__VA_ARGS__)
#define OLOGW(format,...)    OLOG_WARN(format,##__VA_ARGS__)
#define OLOGE(format,...)    OLOG_ERROR(format,##__VA_ARGS__)
#define OLOGF(format,...)    OLOG_FATAL(format,##__VA_ARGS__)

#if(SYS_DEBUG_PRINTF_ENABLE == 0)
#define my_printf(fmt,...)
#else
#define my_printf(fmt,...)   printf(fmt, ##__VA_ARGS__)  
#endif
 
//Log file creation and output 
#define LOG_PRINT(level,fmt,...) my_printf(level "[%s:%d] " fmt, strrchr(__FILE__, '\\') + 1, __LINE__, ##__VA_ARGS__)
#define OLOG_PRINT(level,fmt,...) my_printf(fmt, ##__VA_ARGS__)                            
 
//All
#if LOG_LEVEL_ALL >= LOG_LEVEL
#define LOG_ALL(fmt,...) LOG_PRINT(TITLE_ALL,fmt,##__VA_ARGS__)
#define OLOG_ALL(fmt,...) OLOG_PRINT(TITLE_ALL,fmt,##__VA_ARGS__)
#else
#define LOG_ALL(...)   
#define OLOG_ALL(...) 
#endif
 
//Trace
#if LOG_LEVEL_TRACE >= LOG_LEVEL
#define LOG_TRACE(fmt,...) LOG_PRINT(TITLE_TRACE,fmt,##__VA_ARGS__)
#define OLOG_TRACE(fmt,...) OLOG_PRINT(TITLE_TRACE,fmt,##__VA_ARGS__)
#else
#define LOG_TRACE(...)
#define OLOG_TRACE(...)
#endif
 
//Debug
#if LOG_LEVEL_DEBUG >= LOG_LEVEL
#define LOG_DEBUG(fmt,...)  LOG_PRINT(TITLE_DEBUG,fmt,##__VA_ARGS__)
#define OLOG_DEBUG(fmt,...)  OLOG_PRINT(TITLE_DEBUG,fmt,##__VA_ARGS__)
#else
#define LOG_DEBUG(...)
#define OLOG_DEBUG(...)
#endif
 
//Information 
#if LOG_LEVEL_INFO>= LOG_LEVEL
#define LOG_INFO(fmt,...)   LOG_PRINT(TITLE_INFO,fmt,##__VA_ARGS__)
#define OLOG_INFO(fmt,...)  OLOG_PRINT(TITLE_INFO,fmt,##__VA_ARGS__)
#else
#define LOG_INFO(...)
#define OLOG_INFO(...)
#endif
 
//Warning
#if LOG_LEVEL_WARN >= LOG_LEVEL
#define LOG_WARN(fmt,...)   LOG_PRINT(TITLE_WARN,fmt,##__VA_ARGS__)
#define OLOG_WARN(fmt,...)  OLOG_PRINT(TITLE_WARN,fmt,##__VA_ARGS__)
#else
#define LOG_WARN(...)
#define OLOG_WARN(...)
#endif
 
//Error
#if LOG_LEVEL_ERROR >= LOG_LEVEL
#define LOG_ERROR(fmt,...)  LOG_PRINT(TITLE_ERROR,fmt,##__VA_ARGS__)
#define OLOG_ERROR(fmt,...) OLOG_PRINT(TITLE_ERROR,fmt,##__VA_ARGS__)
#else 
#define LOG_ERROR(...)
#define OLOG_ERROR(...)
#endif
 
//Fatal 
#if LOG_LEVEL_FATAL >= LOG_LEVEL
#define LOG_FATAL(fmt,...)  LOG_PRINT(TITLE_FATAL,fmt,##__VA_ARGS__)
#define OLOG_FATAL(fmt,...) OLOG_PRINT(TITLE_FATAL,fmt,##__VA_ARGS__)
#else
#define LOG_FATAL(...)
#define OLOG_FATAL(...)
#endif

#endif

