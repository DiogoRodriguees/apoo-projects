#pragma once

#include "../Calculator/Calculator.hpp"

#define MAX_DIGITS 8
class CpuDiogo : public Cpu {
private:
    Display* display;
    Operation operation = NOOP;

    Digit memory[MAX_DIGITS];
    Digit digitsOperand1[MAX_DIGITS];
    Digit digitsOperand2[MAX_DIGITS];
    Signal signal_digit_operand1 = POSITIVE;
    Signal signal_digit_operand2 = POSITIVE;
    Signal memorySignal = POSITIVE;

    bool memory_two_free = false;
    int memoryDecimalPosition = -1;
    int memoryDigitsCount = 0;
    int digitsOperand1Count = 0;
    int digitsOperand2Count = 0;
    int decimal_position1 = -1;
    int decimal_position2 = -1;
    int count_equal = 0;

    void reset();
    void operate();
    void addMemory();
    void subMemory();
    void copyToMemory();
    void memoryReadClear();
    void moveMemoryToLeft();
    void showDigits(Digit*, int, int, bool);
    void convertToDigit(int, int*, Digit*, int*, int*, int, Signal*, bool);
    float convertToFloat(int, Digit*, int, Signal);

public:
    void receiveDigit(Digit);
    void setDisplay(Display&);
    void receiveControl(Control);
    void receiveOperation(Operation);
};