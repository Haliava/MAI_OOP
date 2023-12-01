#ifndef LAB2_ARRAY_H
#define LAB2_ARRAY_H
#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <string>
#include <memory>

class Array {
public:
    Array();
    ~Array();
    Array(const std::string &a);
    Array(const std::initializer_list<unsigned char> &t);
    Array(const size_t &n, unsigned char t = 0);
    Array(const Array &other);
    void push_back(unsigned char value);
    void clear();
    void reserve(size_t);
    int get_size();
    int get_size() const;
    unsigned char &operator[](size_t index);
    unsigned char &operator[](size_t index) const;
    bool operator==(const Array& other) const;
private:
    unsigned char *data;
    size_t size;
    size_t capacity;
};


#endif //LAB2_ARRAY_H
