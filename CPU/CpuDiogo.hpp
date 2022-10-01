#pragma once

#include "../Calculator/Calculator.hpp"

#define MAX_DIGITS 8
class CpuDiogo: public Cpu {
private:
    Display* display;
    Operation operation = NOOP;

    Digit memory[MAX_DIGITS];
    Digit digitsOperand1[MAX_DIGITS];
    Digit digitsOperand2[MAX_DIGITS];
    Signal signal_digit_operand1 = POSITIVE;
    Signal signal_digit_operand2 = POSITIVE;
    Signal memory_signal = POSITIVE;

    bool memory_two_free = false;
    int memory_decimal_position = -1;
    int memory_digits_count = 0;
    int digitsOperand1Count = 0;
    int digitsOperand2Count = 0;
    int decimal_position1 = -1;
    int decimal_position2 = -1;

    void reset();
    void operate();
    void copy_to_memory();
    void memory_read_clear();
    void move_memory_to_left();
    void show_digits(Digit*, int, int, bool);
    void convert_to_digit(int, int*, Digit*, int*, int*, int, Signal*, bool);
    float convert_to_float(int, Digit*, int, Signal);

public:
    void receiveDigit(Digit);
    void setDisplay(Display&);
    void receiveControl(Control);
    void receiveOperation(Operation);
};