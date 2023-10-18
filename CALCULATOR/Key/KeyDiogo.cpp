#pragma once

#include "KeyDiogo.hpp"
KeyDiogo::KeyDiogo(char symbol, Digit digit) {
    this->symbol = symbol;
    this->digit = digit;
    this->isDigit = true;
}
KeyDiogo::KeyDiogo(char symbol, Operation operation) {
    this->symbol = symbol;
    this->operation = operation;
    this->isOperation = true;
}

KeyDiogo::KeyDiogo(char symbol, Control control) {
    this->symbol = symbol;
    this->control = control;
    this->isControl = true;
}

void KeyDiogo::press() {
    if (this->isDigit) this->keyboard->receiveDigit(this->digit);
    if (this->isOperation) this->keyboard->receiveOperation(this->operation);
    if (this->isControl) this->keyboard->receiveControl(this->control);
}

void KeyDiogo::setKeyboard(Keyboard& keyboard) {
    this->keyboard = &keyboard;
}

char KeyDiogo::getSymbol() {
    return this->symbol;
}