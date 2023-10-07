#include "Array.h"

Array::Array() : data(nullptr), size(0), capacity(0) {}

Array::Array(const std::string &a) : data(nullptr), size(0), capacity(0) {
    for (int i = 0; i < a.length(); i++) {
        this->push_back(a[i]);
    }
}

Array::Array(const std::initializer_list<unsigned char> &t) : data(nullptr), size(t.size()), capacity(t.size()) {
    for (const unsigned char &value: t) {
        this->push_back(value);
    }
}

Array::Array(const size_t &n, unsigned char t) : data(nullptr), size(n), capacity(n) {
    for (int i = 0; i < n; i++) {
        this->push_back(t);
    }
}

Array::Array(const Array &other) : data(nullptr), size(other.size), capacity(other.capacity) {
    data = new unsigned char[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void Array::push_back(unsigned char value) {
    if (capacity == size) {
        capacity += 1;
    }

    auto *newData = new unsigned char[capacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    data[size++] = value;
}

int Array::get_size() {
    return size;
}

unsigned char &Array::operator[](int index) {
    if (index < size)
        return data[index];
}

unsigned char &Array::operator[](int index) const {
    if (index < size)
        return data[index];
}

bool Array::operator==(const Array &other) const {
    if (size != other.size)
        return false;

    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i])
            return false;
    }

    return true;
}

void Array::clear() {
    this->size = 1;
    this->capacity = 1;
}

int Array::get_size() const {
    return size;
}
