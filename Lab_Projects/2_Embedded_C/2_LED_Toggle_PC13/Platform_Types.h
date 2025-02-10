/*
 * Platform_Types.h
 *
 *  Created on: Sep 16, 2024
 *      Author: ahmed
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*----------------------------------------------------------------------------*/
/*-------------------------------- Types -------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Boolean Type */
typedef unsigned char   	boolean;

/* Character Type */
typedef char            	char_t;

/* Signed Integer Types */
typedef signed char        sint8_t;
typedef signed short       sint16_t;
typedef signed int         sint32_t;
typedef signed long long   sint64_t;

/* Unsigned Integer Types */
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

/* Volatile Signed Integer Types */
typedef volatile signed char        vsint8_t;
typedef volatile signed short       vsint16_t;
typedef volatile signed int         vsint32_t;
typedef volatile signed long long   vsint64_t;

/* Volatile Unsigned Integer Types */
typedef volatile unsigned char      vuint8_t;
typedef volatile unsigned short     vuint16_t;
typedef volatile unsigned int       vuint32_t;
typedef volatile unsigned long long vuint64_t;

/* Floating-Point Types */
typedef float  float32;
typedef double float64;

/*----------------------------------------------------------------------------*/
/*-------------------------------- Defines -----------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif

#endif /* PLATFORM_TYPES_H_ */
