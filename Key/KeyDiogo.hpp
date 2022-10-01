#pragma once

#include "../Calculator/Calculator.hpp"

class KeyDiogo: public Key {
private:
    Keyboard* keyboard;
    char symbol;
    Digit digit;
    Operation operation;
    Control control;
    bool isDigit = false;
    bool isOperation = false;
    bool isControl = false;
public:
    KeyDiogo(char, Digit);
    KeyDiogo(char, Operation);
    KeyDiogo(char, Control);
    void press();
    void setKeyboard(Keyboard&);
    char getSymbol();
};