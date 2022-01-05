/*
 * @Descripttion: macro define
 * @Author: Jerry
 * @Date: 2021-12-03 11:19:44
 * @LastEditTime: 2021-12-31 17:05:53
 * 
 * Copyright © 2021 Jerry, All Rights Reserved
 */
#ifndef _DEFS_H_
#define _DEFS_H_

#define __attr_unused__                 __attribute__((unused))

#define _LE16(x)                        ((u16)(x))
#define _BE16(x)                        ((u16) ((((x)&0xFF) << 8) | (((x)&0xFF00)>>8)))

#define IS_EQUAL(a, b)                  ( (a) == (b) )
#define SET_BIT(v, b)					( (v) |= (0x01<<b) )
#define CLEAR_BIT(v, b)			    	( (v) &= ~(0x01<<b) )
#define IS_BIT_SET(v, b)				( (v) & (0x01<<(b) ) )
#define ABS(x)                          ((x < 0) ? (-x) : (x))

#ifndef BIT
#define BIT(nr)			                (1UL << (nr))
#endif

#define ARRAY_LEN(a)                    (sizeof(a) / sizeof(a[0]))


#define Big_str2u16(s)       ( (((u16_t)(s)[0])<<8) + ((u16_t)(s)[1]) )
#define Big_str2u32(s)       ( (((u32_t)(s)[0])<<24) + (((u32_t)(s)[1])<<16) + \
                               (((u32_t)(s)[2])<<8) + ((u32_t)(s)[3]) )
#define Big_u16ToStr(s, n)    do{  (s)[1] = (u8_t)((n)&0xFF);  (s)[0] = (u8_t)(((n)>>8)&0xFF);  }while(0)
#define Big_u32ToStr(s, n)    do{  (s)[3] = (u8_t)((n)&0xFF);        (s)[2] = (u8_t)(((n)>>8)&0xFF); \
                                   (s)[1] = (u8_t)(((n)>>16)&0xFF);  (s)[0] = (u8_t)(((n)>>24)&0xFF);    }while(0)

#define Little_str2u16(s)      ( (((u16_t)(s)[1])<<8) + ((u16_t)(s)[0]) )
#define Little_str2u32(s)      ( (((u32_t)(s)[3])<<24) + (((u32_t)(s)[2])<<16) + \
                                 (((u32_t)(s)[1])<<8) + ((u32_t)(s)[0]) )
#define Little_u16ToStr(s, n)  do{  (s)[0] = (u8_t)((n)&0xFF);  (s)[1] = (u8_t)(((n)>>8)&0xFF);  }while(0)
#define Little_u32ToStr(s, n)  do{  (s)[0] = (u8_t)((n)&0xFF);        (s)[1] = (u8_t)(((n)>>8)&0xFF); \
                                    (s)[2] = (u8_t)(((n)>>16)&0xFF);  (s)[3] = (u8_t)(((n)>>24)&0xFF);    }while(0)                               

//大端序则为 1，小端序为 0
#if 1
    #define STR_TO_U16(s)    Big_str2u16(s)
    #define STR_TO_U32(s)    Big_str2u32(s)
    #define U16_TO_STR(s, n) Big_u16ToStr(s, n)
    #define U32_TO_STR(s, n) Big_u32ToStr(s, n)
#else
    #define STR_TO_U16(s)    Little_str2u16(s)
    #define STR_TO_U32(s)    Little_str2u32(s)
    #define U16_TO_STR(s, n) Little_u16ToStr(s, n)
    #define U32_TO_STR(s, n) Little_u32ToStr(s, n)
#endif

#endif
