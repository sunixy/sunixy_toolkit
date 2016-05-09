
#include "physical_value.h"
#include <stdio.h>
#include <math.h>

static void physical_value_compare_print(physical_value a, physical_value b) {
    int32_t ret = 0;


    ret = compare_physical_value(a, b);
    printf("a.value=%d, multiplier=%d, b.value=%d, multiplier=%d\r\n",
            a.value, a.multiplier, b.value, b.multiplier);
    printf("a=%f, b=%f\r\n", a.value*powf((float)10, (float)a.multiplier), 
            b.value*powf((float)10, (float)b.multiplier));
    if (ret > 0) {
        printf("a > b\r\n");
    } else if (ret < 0) {
        printf("a < b\r\n");
    } else {
        printf("a = b\r\n");
    }
}

int main(int argc, char *argv[]) {
    physical_value a;
    physical_value b;

    a.value = 5;
    a.multiplier = 1;
    b.value = 50;
    b.multiplier = 0;
    physical_value_compare_print(a, b);

    a.value = 1;
    a.multiplier = 3;
    b.value = 1;
    b.multiplier = 2;
    physical_value_compare_print(a, b);

    a.value = 1;
    a.multiplier = 2;
    b.value = 1;
    b.multiplier = -3;
    physical_value_compare_print(a, b);

    a.value = 100;
    a.multiplier = -2;
    b.value = 1000;
    b.multiplier = -3;
    physical_value_compare_print(a, b);
}

