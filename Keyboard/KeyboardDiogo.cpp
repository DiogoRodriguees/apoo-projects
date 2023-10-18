#include "KeyboardDiogo.hpp"

void KeyboardDiogo::receiveDigit(Digit digit) {
    this->cpu->receiveDigit(digit);
}
void KeyboardDiogo::receiveOperation(Operation operation) {
    this->cpu->receiveOperation(operation);
}
void KeyboardDiogo::receiveControl(Control control) {
    this->cpu->receiveControl(control);
}

void KeyboardDiogo::addKey(Key& key) {
    this->keys[this->keysCount++] = &key;
    key.setKeyboard(*this);
}

Key& KeyboardDiogo::findKey(char symbol) {
    for (int i = 0; i < this->keysCount; i++)
        if (this->keys[i]->getSymbol() == symbol)
            return *this->keys[i];

    throw "KEY_NOT_FOUND";
}

void KeyboardDiogo::setCpu(Cpu& cpu) {
    this->cpu = &cpu;
}
