/*copyright (c) 2021 AlanCui*/
#ifndef _LIMITS_H_
#define _LIMITS_H_
//Unsigned 64 bits
#define U64_MAX 0xffffffffffffffff
#define U64_MIN 0
//Unsigned 32 bits
#define U32_MAX 0xffffffff
#define U32_MIN 0
//Signed 32 bits
#define S32_MAX 0x7fffffff
#define S32_MIN -2147483648
//Unsigned 16 bits
#define U16_MAX 0xffff
#define U16_MIN 0
//Signed 16 bits 
#define S16_MAX 0x7fff
#define S16_MIN -32768
//Unsigned 8 bits 
#define U8_MAX 256
#define U8_MIN 0
//Signed 8 bits
#define S8_MAX 127
#define S8_MIN -128
//Unsigned long long 
#define ULLONG_MAX U64_MAX
#define ULLONG_MIN U64_MIN
//Unsigned long
#define ULONG_MAX U32_MAX
#define ULONG_MIN U32_MIN
//Signed long
#define LONG_MAX S32_MAX
#define LONG_MIN S32_MIN
//Unsigned int
#define UINT_MAX ULONG_MAX
#define UINT_MIN ULONG_MIN
//Signed int
#define INT_MAX LONG_MAX
#define INT_MIN LONG_MIN
//Unsigned short
#define USHORT_MAX U16_MAX
#define USHORT_MIN U16_MIN
//Signed short
#define SHORT_MAX S16_MAX
#define SHORT_MIN S16_MIN
//Size_t
#define SIZE_T_MAX ULONG_MAX
#endif