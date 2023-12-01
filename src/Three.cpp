#include <iostream>
#include "../include/Three.h"

const int BASE = 3;

Three::Three(int number) {
    while (number > 0) {
        this->number.push_back(std::to_string(number % 10)[0]);
        number /= 10;
    }

    this->print();
}

Three::Three(const std::string &source) {
    for (int i = source.length() - 1; i >= 0; --i) {
        this->number.push_back(source[i]);
    }

    this->print();
}

Three::Three(const Array &source) {
    this->number = source;
}

Three Three::operator+(const Three &other) {
    Array result;
    int minLength = std::min(this->number.get_size(), other.number.get_size());
    int maxLength = std::max(this->number.get_size(), other.number.get_size());
    bool isLonger = this->number.get_size() > other.number.get_size();
    bool hasOverflow;
    int current;

    for (int i = 0; i < minLength; ++i) {
        current = this->number[i] - '0' + other.number[i] - '0' + (int) hasOverflow;
        hasOverflow = current / BASE > 0;
        result.push_back(
                hasOverflow ?
                std::to_string(current - BASE)[0] :
                std::to_string(current % BASE)[0]);
    }

    for (int i = minLength; i < maxLength; ++i) {
        current = (isLonger ? this->number[i] : other.number[i]) - '0' + (int) hasOverflow;
        hasOverflow = current / BASE > 0;
        result.push_back(
                hasOverflow ?
                std::to_string(current - BASE)[0] :
                std::to_string(current % BASE)[0]);
    }

    if (hasOverflow) result.push_back('1');

    return {result};
}

Three Three::operator-(const Three &other) {
    if (other.number.get_size() > this->number.get_size() || *this < other)
        throw std::invalid_argument("Can't subtract bigger number from the smaller one");

    Array resultArr;
    bool hasOverflow;
    int current;

    for (int i = 0; i < other.number.get_size(); ++i) {
        current = (hasOverflow && this->number[i] == '0' ?
                   BASE :
                   this->number[i] - '0') - hasOverflow - (other.number[i] - '0');
        if (current < 0) {
            current = BASE - (other.number[i] - '0' - (this->number[i] - '0'));
            hasOverflow = true;
        } else hasOverflow = false;

        resultArr.push_back(std::to_string(current)[0]);
    }

    for (int i = other.number.get_size(); i < this->number.get_size(); ++i) {
        current = this->number[i] - '0' + BASE * (int) hasOverflow;
        hasOverflow = current / BASE > 0;
        resultArr.push_back(
                hasOverflow ?
                std::to_string(current - BASE)[0] :
                std::to_string(current % BASE)[0]);
    }
    (Three{resultArr}).print();
    Three result{this->removeLeadingZeros(Three{resultArr})};
    return {result};
}

void Three::print() {
    for (int i = this->number.get_size() - 1; i >= 0; --i) {
        std::cout << this->number[i];
    }
    std::cout << std::endl;
}

bool Three::operator==(const Three &other) {
    if (other.number.get_size() != this->number.get_size()) return false;

    for (int i = 0; i < other.number.get_size(); ++i) {
        if (this->number[i] != other.number[i])
            return false;
    }

    return true;
}

bool Three::operator>(const Three &other) {
    if (this->number.get_size() != other.number.get_size() || this == &other)
        return this->number.get_size() > other.number.get_size();

    for (int i = this->number.get_size() - 1; i >= 0; --i) {
        if (this->number[i] != other.number[i])
            return this->number[i] > other.number[i];
    }

    return false;
}

bool Three::operator<(const Three &other) {
    if (this->number.get_size() != other.number.get_size() || this == &other)
        return this->number.get_size() > other.number.get_size();

    return !(Three{this->number} > Three{other});
}

unsigned char Three::operator[](int i) {
    return this->number[i];
}

Three Three::removeLeadingZeros(const Three &source) {
    int i = source.number.get_size() - 1;
    while (i >= 0) {
        if (source.number[i] == '0') --i;
        else break;
    }

    std::cout << i << " dd" << std::endl;
    Array newNumber;
    for (int j = 0; j <= i; ++j) {
        newNumber.push_back(source.number[j]);
    }

    return {newNumber};
}