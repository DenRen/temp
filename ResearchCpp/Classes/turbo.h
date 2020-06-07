//
// Created by tester on 07.06.2020.
//

#ifndef RESEARCHCPP_TURBO_H
#define RESEARCHCPP_TURBO_H


struct turbo {
    static int id;
    int local_id;
    int force;

    turbo ();
    turbo (int force);
    ~turbo ();

    turbo operator+(const turbo& other);
    turbo& operator= (const turbo& other);
};


#endif //RESEARCHCPP_TURBO_H
