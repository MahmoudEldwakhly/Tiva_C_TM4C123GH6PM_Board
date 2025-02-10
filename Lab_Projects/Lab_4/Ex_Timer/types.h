#ifndef _TYPES_H
#define _TYPES_H



#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

typedef char sint8;
typedef unsigned char uint8;
typedef volatile char vsint8;
typedef char* int8_ptr;
typedef unsigned char* uint8_ptr;

typedef short sint16;
typedef unsigned short uint16;
typedef short* int16_ptr;
typedef unsigned short* uint16_ptr;
typedef volatile short vsint16;

typedef int sint32;
typedef unsigned int uint32;
typedef int* int32_ptr;
typedef unsigned int* uint32_ptr;
typedef volatile int vsint32;

typedef long long sint64;
typedef unsigned long long uint64;
typedef long long* int64_ptr;
typedef unsigned long long* uint64_ptr;
typedef volatile long long vsint64;

typedef float float32;
typedef double float64;

#endif /*_TYPES_H*/