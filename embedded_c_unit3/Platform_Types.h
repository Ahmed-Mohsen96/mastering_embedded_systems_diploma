/*
 * Platform_Types.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Ahmed mohsen
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include<stdbool.h>


#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE			CPU_TYPE_32
#define CPU_BIT_ORDER		MSB_FIRST
#define CPU_BYTE_ORDER		HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE		(boolean)false
#endif
#ifndef TRUE
#define TRUE		(boolean)true
#endif

typedef _Bool				boolean;
typedef signed char			sint8_t;
typedef unsigned char 		uint8_t;
typedef char				char_t;
typedef short				int16_t;
typedef unsigned short		uint16_t;
typedef int					int32_t;
typedef unsigned int		uint32_t;
typedef long long			int64_t;
typedef unsigned long long	uint64_t;

////////////////////
typedef volatile signed char 				vint8_t;
typedef volatile unsigned char				vuint8_t;

typedef volatile short						vint16_t;
typedef volatile unsigned short				vuint16_t;

typedef volatile int						vint32_t;
typedef volatile unsigned int				vuint32_t;

typedef volatile long long					vint64_t;
typedef volatile unsigned long long			vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
