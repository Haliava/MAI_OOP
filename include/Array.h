#ifndef LAB2_ARRAY_H
#define LAB2_ARRAY_H
#include <cstddef>
#include <initializer_list>
#include <string>

class Array {
public:
    Array();
    Array(const size_t& n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char> &t);
    Array(const std::string &t);

    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

private:
    unsigned char array[];
};


#endif //LAB2_ARRAY_H
