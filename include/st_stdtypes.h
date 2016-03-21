/*  
 *  sunixy toolkit 
 *  
 */

#ifndef _ST_STDTYPES_H_
#define _ST_STDTYPES_H_
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
typedef signed char int8_t;

typedef signed int short int16_t;

typedef signed long int32_t;

typedef unsigned char uint8_t;

typedef unsigned int short uint16_t;

typedef unsigned long uint32_t;

#define NULL        (void *)0

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /*_ST_STDTYPES_H_*/
