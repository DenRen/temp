#ifndef RESEARCHCPP_VECTOR_H
#define RESEARCHCPP_VECTOR_H



class Vector {
private:
    typedef long data_t;    // Only signed and integer

    data_t *buf_;
    data_t size;
    data_t maxsize;

public:

    explicit Vector (data_t length);
            ~Vector ();

    data_t& operator[] (const data_t n) const;

    void Dump (FILE *log_file = stdout) const;
    bool ok () const;

};

#endif //RESEARCHCPP_VECTOR_H
