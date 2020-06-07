#include <cstdlib>
#include <stdexcept>
#include <cassert>
#include "Vector.h"

Vector::Vector (data_t length)/*:
    buf_ ((data_t*) calloc (sizeof (data_t), length)),
    size (0),
    maxsize (length)  */
{
    if (length <= 0)
        throw std::invalid_argument {"Negative array length! How so?\n"};

    this->size = 0;
    this->maxsize = length;
    if ((this->buf_ = (data_t*) calloc (sizeof (data_t), length)) == nullptr)
        throw std::runtime_error {"Failed to create a buffer for Vector\n"};

    printf ("Vector is created\n");
}

Vector::~Vector () {
    size = maxsize = -1983;         // Key number for deleted Vector
    free (buf_);
    buf_ = nullptr;

    printf ("The Vector has been destroyed\n");
};

Vector::data_t& Vector::operator[] (const data_t n) const {
    assert (ok ());
    return buf_[n];
}

void Vector::Dump (FILE *log_file) const {
#define left_up__       218
#define right_up__      191
#define left_down__     192
#define right_down__    217
#define mid_line__      196
#define ver_line__      179
#define write_(symb)        fprintf (log_file, "%c", symb);
#define write_endl(symb)    fprintf (log_file, "%c\n", symb);
#define write_w(symb)       fprintf (log_file, "%s", symb);

    const unsigned mid_len = 2 * (22 + 10) + 3;
    unsigned temp = 0;

    write_ (left_up__)   // Top line
    temp = 10;
    while (temp--)  printf ("%c", mid_line__);
    write_ (194)
    temp = mid_len - 11;
    while (temp--)  printf ("%c", mid_line__);
    write_endl (right_up__)

    write_  (ver_line__)
    write_w ("   DUMP   ")
    write_  (ver_line__)
    write_  (' ')

    write_w ("                Vector: ")
    fprintf (log_file, "%p                 ", buf_);
    write_endl  (ver_line__)

    write_ (195)
    temp = 10;
    while (temp--)  printf ("%c", mid_line__);
    write_ (197)
    temp = 22;
    while (temp--)  printf ("%c", mid_line__);
    write_ (194)
    temp = 10;
    while (temp--)  printf ("%c", mid_line__);
    write_ (194)
    temp = 22;
    while (temp--)  printf ("%c", mid_line__);
    write_endl (180)

    for (size_t pair = 0; pair < maxsize / 2; pair++) {
        write_ (ver_line__)
        fprintf (log_file, "%10ld%c%22ld%c",   pair * 2,     ver_line__, buf_[2 * pair],     ver_line__);
        fprintf (log_file, "%10ld%c%22ld%c\n", pair * 2 + 1, ver_line__, buf_[2 * pair + 1], ver_line__);
    }

    if (maxsize % 2) {
        write_ (ver_line__)
        fprintf (log_file, "%10ld%c%22ld%c", maxsize, ver_line__, buf_[maxsize - 1], 195);
        temp = 10;
        while (temp--)  printf ("%c", mid_line__);
        write_ (193);
        temp = 22;
        while (temp--)  printf ("%c", mid_line__);
        write_endl (right_down__);
    } else {
        write_ (left_down__)
        temp = 10;
        while (temp--)  printf ("%c", mid_line__);
        write_ (193)
        temp = 22;
        while (temp--)  printf ("%c", mid_line__);
        write_ (193)
        temp = 10;
        while (temp--)  printf ("%c", mid_line__);
        write_ (193)
        temp = 22;
        while (temp--)  printf ("%c", mid_line__);
        write_endl (217)
    }
#undef write_
#undef write_endl
#undef write_w
#undef ver_line__
#undef mid_line__
#undef right_down__
#undef left_down__
#undef right_up__
#undef left_up__
}

bool Vector::ok () const {
    if (maxsize <= 0 && buf_ != nullptr  ||
        maxsize >  0 && (size < 0 || size >= maxsize))
        throw std::runtime_error {"Vector: The verifier is angry"};
}