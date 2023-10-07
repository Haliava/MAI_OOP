#ifndef LAB2_ARRAY_H
#define LAB2_ARRAY_H
#include <cstddef>
#include <initializer_list>
#include <string>

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
    int get_size();
    int get_size() const;
    unsigned char &operator[](int index);
    unsigned char &operator[](int index) const;
    bool operator==(const Array& other) const;
private:
    unsigned char *data;
    int size;
    int capacity;
};


#endif //LAB2_ARRAY_H
