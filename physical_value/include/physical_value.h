
#ifndef _ST_PHYSICAL_VALUE_H_
#define _ST_PHYSICAL_VALUE_H_
#include <st_stdtypes.h>

typedef struct tagpyhsical_value {
    uint16_t value;
    int8_t multiplier;
} physical_value;

int32_t compare_physical_value(physical_value a, physical_value b);

#endif /*_ST_PHYSICAL_VALUE_H_*/
