
#include "DisplayDiogo.hpp"

#include <stdio.h>

void DisplayDiogo::refresh() {
    console.set_color(Color::FG_Black);
    console.set_color(Color::FG_White);
    console.clear_screen();

    if (signal == NEGATIVE) {
        this->showDigitShape("      ", "    ", "====", "    ", "    ", 0);
    }
    else {
        // this->showDigitShape("      ", "  ++  ", " ++++ ", "  ++  ", "    ", 0);
        this->showDigitShape("    ", "    ", "    ", "    ", "    ", 0);
    }

    for (int i = 1; i <= this->digitsCount; i++) {
        switch (this->digits[i - 1]) {
        case ZERO:
            this->showDigitShape("######", "##  ##", "##  ##", "##  ##", "######", i);
            break;
        case ONE:
            this->showDigitShape("   ##", "  ### ", "   ##", "   ##", " #####", i);
            break;
        case TWO:
            this->showDigitShape("##### ", "    ##", "  ## ", "##  ", "######", i);
            break;
        case THREE:
            this->showDigitShape("######", "    ##", "  ####", "    ##", "######", i);
            break;
        case FOUR:
            this->showDigitShape("##  ##", "##  ##", "######", "    ##", "    ##", i);
            break;
        case FIVE:
            this->showDigitShape("######", "##    ", "######", "    ##", "######", i);
            break;
        case SIX:
            this->showDigitShape("######", "##    ", "######", "##  ##", "######", i);
            break;
        case SEVEN:
            this->showDigitShape("######", "    ##", "  ##  ", "##     ", "##    ", i);
            break;
        case EIGHT:
            this->showDigitShape("######", "##  ##", "######", "##  ##", "######", i);
            break;
        case NINE:
            this->showDigitShape("######", "##  ##", "######", "    ##", "######", i);
            break;
        case NO_DIGIT:/* this->showDigitShape("", "", "", "", "", i); */
            break;
        default:
            this->showDigitShape("", "", "", "", "", i);
        }

        if (this->decimal_position != -1 && this->decimal_position == i) {
            printf(" #");
        }
    }

}

void DisplayDiogo::showDigitShape(const char* line1, const char* line2, const char* line3, const char* line4, const char* line5, unsigned char column) {
    this->console.set_cursor(1, 1 + column * 9);printf("%s", line1);
    this->console.set_cursor(2, 1 + column * 9);printf("%s", line2);
    this->console.set_cursor(3, 1 + column * 9);printf("%s", line3);
    this->console.set_cursor(4, 1 + column * 9);printf("%s", line4);
    this->console.set_cursor(5, 1 + column * 9);printf("%s", line5);
}

DisplayDiogo::DisplayDiogo() {
    this->console.init(0, 0);
    this->clear();
}

void DisplayDiogo::addDigit(Digit digit, bool withDot = false) {
    if (digit == NO_DIGIT) {
        if (withDot == true && this->decimal_position == -1) {
            this->decimal_position = digitsCount;
        }
        this->refresh();
        return;
    }
    if (this->digitsCount < MAX_DIGITS) {
        digits[this->digitsCount++] = digit;

        if (withDot == true && this->decimal_position == -1) {
            this->decimal_position = digitsCount;
        }
        this->refresh();
    }
}

void DisplayDiogo::setSignal(Signal signal) {
    this->signal = signal;
    this->refresh();
}

void DisplayDiogo::clear() {
    this->digitsCount = 0;
    this->signal = POSITIVE;
    this->decimal_position = -1;
    this->refresh();
}
