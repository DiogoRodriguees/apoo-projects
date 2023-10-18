#pragma once
#include "../Calculator/Calculator.hpp"
#include "../Console/Console.hpp"
#define MAX_DIGITS 8

class DisplayDiogo : public Display {
private:
    Console console;
    Digit digits[MAX_DIGITS];
    unsigned char digitsCount;
    int decimal_position = -1;
    Signal signal;
    void refresh();
    void showDigitShape(const char* line1, const char* line2, const char* line3, const char* line4, const char* line5, unsigned char column);

public:
    DisplayDiogo();
    void addDigit(Digit digit, bool);
    void setSignal(Signal signal);
    void clear();
};