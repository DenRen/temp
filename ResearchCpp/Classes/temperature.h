//
// Created by tester on 07.06.2020.
//

#ifndef RESEARCHCPP_TEMPERATURE_H
#define RESEARCHCPP_TEMPERATURE_H

#define ZERO_CELSIUS_IN_KELVIN 273.15   // +- 0.01

struct temperature {
    long double kelvin { 0 };

    friend temperature operator"" _K (long double value);
    friend temperature operator"" _C (long double value);

    long double _K () const;
    long double _C () const;

    void dump (bool tab = false);
private:
    explicit temperature (long double kelvin) : kelvin (kelvin) {};
};

temperature operator"" _K (long double value);
temperature operator"" _C (long double value);

#endif //RESEARCHCPP_TEMPERATURE_H
