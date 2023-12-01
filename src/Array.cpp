#include "../include/Array.h"

Array::Array() : size(0), capacity(1) {
    data = reinterpret_cast<unsigned char*>(new int8_t[sizeof(unsigned char)]);
}

Array::Array(const std::string &a) : Array() {
    for (char c: a) {
        this->push_back(c);
    }

    this->size = a.length();
    this->capacity = a.length();
}

Array::~Array() = default;

Array::Array(const std::initializer_list<unsigned char> &t) : data(nullptr), size(t.size()), capacity(t.size()) {
    for (const unsigned char value: t) {
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
    if (this->capacity == this->size) {
        if (this->capacity * 2 < this->capacity)
            throw std::out_of_range("too big");

        reserve(2 * this->capacity);
    }

    new (this->data + this->size) unsigned char(value);
    ++this->size;
}

void Array::reserve(size_t newCapacity) {
    if (newCapacity <= this->capacity)
        return;

    auto* newData = reinterpret_cast<unsigned char*>(new int8_t[sizeof(unsigned char) * newCapacity]);
    try {
        std::uninitialized_copy(this->data, this->data + this->size, newData);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newData); // 1 byte
        throw;
    }

    delete[] reinterpret_cast<int8_t*>(this->data); // 1 byte
    this->data = newData;
    this->capacity = newCapacity;
}

int Array::get_size() {
    return size;
}

unsigned char &Array::operator[](size_t index) {
    if (index < size)
        return data[index];
}

unsigned char &Array::operator[](size_t index) const {
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
