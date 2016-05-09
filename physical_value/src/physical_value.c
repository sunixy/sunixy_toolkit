
#include "physical_value.h"
#include <stdio.h>

static uint16_t math_power_limit(int8_t multiplier) {
    int16_t i = 0;
    uint16_t ret = 0;
    for (i = 0; i < multiplier; i++) {
        if (0 == i) {
            ret = 10;
        } else {
            ret *= 10;
        }
    }
    return ret;
}

int32_t compare_physical_value(physical_value a, physical_value b) {
    int32_t ret = 0;

    if ((a.value == b.value) && (a.multiplier == b.multiplier)) {
        return ret;
    } 
    if (a.multiplier > b.multiplier) {
        ret = ((int32_t)a.value*math_power_limit(a.multiplier-b.multiplier))-b.value;
    } else if (a.multiplier < b.multiplier) {
        ret = ((int32_t)b.value*math_power_limit(b.multiplier-a.multiplier))-a.value;
    } else {
        ret = a.value - b.value;
    }

    return ret;
}

