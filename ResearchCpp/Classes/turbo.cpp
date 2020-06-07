//
// Created by tester on 07.06.2020.
//

#include <cstdio>
#include "turbo.h"

int turbo::id = 0;


turbo& turbo::operator= (const turbo& other) {
    force = other.force;

    return *this;
}

turbo turbo::operator+ (const turbo& other) {
    printf ("Force left:  %d\n"
            "Force right: %d\n", force, other.force);
    force += other.force;

    return *this;
}

turbo::turbo () :
        force (-1),
        local_id (id++)
{
    printf ("%2d) Contructor ()\n", local_id);
}

turbo::turbo (int force) :
        force (force),
        local_id (id++)
{
    printf ("%2d) Constructor (%d)\n", local_id, force);
}

turbo::~turbo () {
    printf ("%2d) Destructor ()\n", local_id);
}
