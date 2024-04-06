#ifndef _STD_TYPES_
#define _STD_TYPES_

typedef unsigned char            u8; 
typedef unsigned short int       u16;        
typedef unsigned int             u32;
typedef unsigned long int        u64;

typedef signed char              s8;
typedef signed short int         s16;
typedef signed int               s32;           
typedef signed long long         s64;

typedef float                    f32;
typedef double                   f64;	


typedef volatile char                       vchar_t;
typedef volatile signed char                vsint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile signed long long int       vsint64_t;


typedef volatile unsigned char              vuint8_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile unsigned long long int     vuint64_t;


#define NULL		(void*)0


#endif
