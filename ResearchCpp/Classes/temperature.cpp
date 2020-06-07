//
// Created by tester on 07.06.2020.
//

#include <cstdio>
#include "temperature.h"

temperature operator"" _K (long double value) {
    return temperature (value);
}

temperature operator"" _C (long double value) {
    return temperature (value + ZERO_CELSIUS_IN_KELVIN);
}

long double temperature::_K () const {
    return kelvin;
}

long double temperature::_C () const{
    return kelvin - ZERO_CELSIUS_IN_KELVIN;
}

void temperature::dump (bool tab) {
    if (tab)
        printf ("\tKelvin: %3.2Lf\n\tCelsuis: %3.2Lf\n",
                kelvin, kelvin - ZERO_CELSIUS_IN_KELVIN);
    else
        printf ("Kelvin: %3.2Lf\nCelsuis: %3.2Lf\n",
                kelvin, kelvin - ZERO_CELSIUS_IN_KELVIN);
}
