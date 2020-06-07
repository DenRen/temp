#include <cstdio>
#include <cstdlib>
#include <new>
#include <cwchar>
#include <string>
#include <iostream>
#include "Classes/temperature.h"


int main () {
    temperature room_temp = 16.0_C;
    temperature helium_temp = 4.2_K;

    printf ("Room:\n");
    room_temp.dump (true);
    printf("\n");

    printf ("Liquid helium:\n");
    helium_temp.dump (true);
    printf("\n");
}