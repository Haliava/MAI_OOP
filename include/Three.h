#ifndef LAB2_THREE_H
#define LAB2_THREE_H

#include "string"
#include "vector"
#include "Array.h"

class Three {
    public:
        Three(int number);
        Three(const std::string& source);
        Three(const Array& source);

        Three operator+ (const Three& other);
        Three operator- (const Three& other);
        unsigned char operator[] (int i);
        bool operator== (const Three& other);
        bool operator> (const Three& other);
        bool operator< (const Three& other);
        void print();
        Three removeLeadingZeros(const Three& source);
    private:
        Array number;
};

#endif //LAB2_THREE_H
