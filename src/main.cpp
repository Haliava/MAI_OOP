#include <iostream>
#include <map>
#include "../include/Three.h"

enum OPERATIONS {
    ADD,
    SUBTRACT,
    MORE,
    LESS,
    EQ,
};

int main() {
    std::string inputNum1;
    std::string inputNum2;
    std::string operation;

    std::map<std::string, int> operationsMap {
            {"+", ADD}, {"-", SUBTRACT},
            {">", MORE}, {"<", LESS},
            {"=", EQ}
    };

    std::cin >> inputNum1 >> operation >> inputNum2;
    Three num1 {inputNum1};
    Three num2 {inputNum2};

    Three result {0};
    bool boolResult;

    switch (operationsMap[operation]) {
        case ADD:
            result = num1 + num2;
            break;
        case SUBTRACT:
            result = num1 - num2;
            break;
        case MORE:
            boolResult = num1 > num2;
            break;
        case LESS:
            boolResult = num1 < num2;
            break;
        case EQ:
            boolResult = num1 == num2;
            break;
    }

    if (operationsMap[operation] == ADD || operationsMap[operation] == SUBTRACT)
        result.print();
    else
        std::cout << boolResult << std::endl;

    return 0;
}
