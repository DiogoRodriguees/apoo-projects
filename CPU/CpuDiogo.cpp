#include "CpuDiogo.hpp"
#include <iostream>
#include <math.h>
#include <string.h>

/******************************************************
*               FUNÇÕES AUXILIARES                    *
*******************************************************/
void CpuDiogo::moveMemoryToLeft() {
    for (int i = 0; i < 8; i++) {
        this->digitsOperand1[i] = this->digitsOperand2[i];
    }
    this->decimal_position1 = this->decimal_position2;
    this->signal_digit_operand1 = this->signal_digit_operand2;
    this->digitsOperand1Count = this->digitsOperand2Count;
    this->signal_digit_operand2 = POSITIVE;
    this->decimal_position2 = -1;
    this->digitsOperand2Count = 0;
}

/******************************************************
*        COPY OF MEMORY TWO FOR MEMORY RESERV         *
*******************************************************/
void CpuDiogo::copyToMemory() {
    for (int i = 0; i < 8; i++) {
        this->memory[i] = this->digitsOperand2[i];
    }
    this->memory_decimal_position = this->decimal_position2;
    this->memory_digits_count = this->digitsOperand2Count;
    this->memory_signal = this->signal_digit_operand2;
}

/******************************************************
*               READ MEMORY CONTENTS                  *
*******************************************************/
void CpuDiogo::memoryReadClear() {
    bool signal = this->memory_signal == NEGATIVE ? true : false;
    showDigits(this->memory, this->memory_digits_count, this->memory_decimal_position, signal);
    for (int i = 0; i < 8; i++) {
        this->memory[i] = ZERO;
    }
    this->memory_decimal_position = -1;
    this->memory_digits_count = 0;
    this->memory_signal = POSITIVE;

}

/******************************************************
*                RESET ALL MEMORIES                   *
*******************************************************/
void CpuDiogo::reset() {
    this->decimal_position1 = -1;
    this->decimal_position2 = -1;
    this->digitsOperand2Count = 0;
    this->digitsOperand1Count = 0;
    this->operation = NOOP;
}


/******************************************************
*                    SET DISPLAY                      *
*******************************************************/
void CpuDiogo::setDisplay(Display& display) {
    this->display = &display;
}

/******************************************************
*                   RECEIVE DIGIT                     *
*******************************************************/
void CpuDiogo::receiveDigit(Digit digit) {
    /* Guardar o dígito no operando correspondente */
    if (this->operation == NOOP) {
        this->digitsOperand1[this->digitsOperand1Count++] = digit;
    }
    else {
        if (this->digitsOperand2Count > 0 && memory_two_free) {
            moveMemoryToLeft();
            this->display->clear();
            this->digitsOperand2Count = 0;
            memory_two_free = false;
            this->count_equal = 0;

        }
        this->digitsOperand2[this->digitsOperand2Count++] = digit;
    }

    /* Exibir o dígito na tela */
    this->display->addDigit(digit);

}

/******************************************************
*                 RECEIVE OPERATION                   *
*******************************************************/
void CpuDiogo::receiveOperation(Operation operation) {

    if (operation == EQUAL && this->digitsOperand2Count > 0) {
        this->count_equal++;
        this->operate();
        return;
    }

    if (this->operation != NOOP && this->digitsOperand2Count > 0) {
        if (this->count_equal == 0) {
            this->count_equal = 0;
            this->operate();

        }
    }

    this->operation = operation;
}

/******************************************************
*                  RECEIVE CONTROL                    *
*******************************************************/
void CpuDiogo::receiveControl(Control control) {
    switch (control) {
    case ON_CLEAR_ERROR: this->display->clear();
        break;
    case DECIMAL_SEPARATOR:


        if (this->digitsOperand2Count > 0 && this->decimal_position2 == -1) {
            this->decimal_position2 = this->digitsOperand2Count - 1;
            this->display->addDigit(NO_DIGIT, true);
            return;

        }
        if (this->digitsOperand1Count > 0 && this->decimal_position1 == -1) {
            this->decimal_position1 = this->digitsOperand1Count - 1;
            this->display->addDigit(NO_DIGIT, true);
            return;
        }
        if (this->digitsOperand1Count == 0 && this->decimal_position1 == -1) {
            this->receiveDigit(ZERO);
            this->decimal_position1 = 0;
            return;
        }
        else if (this->digitsOperand2Count == 0 && this->decimal_position2 == -1) {
            this->receiveDigit(ZERO);
            this->decimal_position2 = 0;
            return;

        }
        break;
    case OFF: reset();
        break;
    case MEMORY_READ_CLEAR: memoryReadClear();
        break;
    case MEMORY_ADDITION:
        break;
    case MEMORY_SUBTRACTION:
        break;
    }
}

/******************************************************
*               SHOW DIGIT ON DISPLAY                 *
*******************************************************/
void CpuDiogo::showDigits(Digit* array, int size_array, int dot_position, bool have_signal) {
    this->display->clear();

    int i = 0;
    if (have_signal) this->display->setSignal(NEGATIVE);

    while (i < size_array)
    {
        if (i != dot_position) {
            this->display->addDigit(array[i++]);
        }
        else {
            this->display->addDigit(array[i++], true);
        }
    }
}

/******************************************************
*              CONVERT DIGIT TO FLOAT                 *
*******************************************************/
float CpuDiogo::convertToFloat(int quantidae_de_operandos, Digit* array, int decimal_position, Signal signal) {
    int resultado = 0;

    for (int i = 0; i < quantidae_de_operandos; i++)
    {
        switch (array[i]) {
        case ZERO: resultado *= 10; resultado += 0;
            break;
        case ONE: resultado *= 10; resultado += 1;
            break;
        case TWO: resultado *= 10;resultado += 2;
            break;
        case THREE: resultado *= 10;resultado += 3;
            break;
        case FOUR: resultado *= 10;resultado += 4;
            break;
        case FIVE: resultado *= 10; resultado += 5;
            break;
        case SIX: resultado *= 10; resultado += 6;
            break;
        case SEVEN: resultado *= 10;resultado += 7;
            break;
        case EIGHT: resultado *= 10;resultado += 8;
            break;
        case NINE: resultado *= 10; resultado += 9;
            break;
        default:
            break;
        }
    }

    float resultado_em_float = resultado;
    float dividendo = 1;
    int number_float = quantidae_de_operandos - (decimal_position + 1);

    if (decimal_position != -1) {
        dividendo = pow(10, number_float);
        resultado_em_float = resultado / (dividendo);
    }

    if (signal == NEGATIVE) resultado_em_float = resultado_em_float * (-1);
    return resultado_em_float;
}

/******************************************************
*              CONVERT FLOAT TO DIGIT                 *
*******************************************************/
void CpuDiogo::convertToDigit(int size_array, int* array, Digit* memory, int* count, int* decimal, int decimal_position, Signal* signal, bool have_signal) {
    int j = 0;
    *count = 0;
    *decimal = decimal_position;
    if (have_signal) *signal = NEGATIVE;

    for (int i = size_array - 1; i >= 0; i--) {

        switch (array[i]) {
        case 0:     memory[j++] = ZERO;
            break;
        case 1:    memory[j++] = ONE;
            break;
        case 2:    memory[j++] = TWO;
            break;
        case 3:   memory[j++] = THREE;
            break;
        case 4:   memory[j++] = FOUR;
            break;
        case 5:    memory[j++] = FIVE;
            break;
        case 6:    memory[j++] = SIX;
            break;
        case 7:    memory[j++] = SEVEN;
            break;
        case 8:    memory[j++] = EIGHT;
            break;
        case 9:   memory[j++] = NINE;
            break;
        default:
            break;
        }
        *count = *count + 1;;
    }

}

/******************************************************
*         SEARCH DECIMAL POSITION FROM RESULT         *
*******************************************************/
int searchDecimalPosition(float number) {
    int part_inteira = number;
    int count = -1;

    if ((number - part_inteira) <= 0)  return -1;

    if (number > 0 && number < 1)  return count + 1;

    while (part_inteira > 0) {
        count++;
        part_inteira /= 10;
    }

    return count;
}

/******************************************************
*                 MAKE OPERATION                      *
*******************************************************/
void CpuDiogo::operate() {
    float memory_one = convertToFloat(this->digitsOperand1Count, this->digitsOperand1, this->decimal_position1, this->signal_digit_operand1);
    float memory_two = convertToFloat(this->digitsOperand2Count, this->digitsOperand2, this->decimal_position2, this->signal_digit_operand2);
    float result = 0;

    // ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, EQUAL, NOOP
    switch (this->operation) {
    case ADDITION: result = memory_one + memory_two;
        break;
    case SUBTRACTION: result = memory_one - memory_two;
        break;
    case MULTIPLICATION: result = memory_one * memory_two;
        break;
    case DIVISION: result = memory_one / memory_two;
        break;
    }

    bool have_signal = false;
    float preserv_result = result;

    if (result < 0) {
        have_signal = true;
        result *= -1;
    }

    int i = 0;
    int result_integer = result;
    int array_with_result[8] = { 0,0,0,0,0,0,0,0 };
    int result_decimal_position = searchDecimalPosition(result);

    while ((result - result_integer) > 0) {
        result *= 10;
        result_integer = result;
    }

    result_integer = result;
    while (result_integer > 0) {
        array_with_result[i++] = result_integer % 10;
        result_integer /= 10;
    }

    // Para numeros nos intervalos ]-1,-0.1] e [0.1, 1[
    if (preserv_result > 0.09 && preserv_result < 1) array_with_result[i++] = 0;

    // Para numeros nos intervalos [-0.09, 0[ e ]0, 0.09]
    if (preserv_result > 0 && preserv_result < 0.1) {
        while ((int)preserv_result < 1) {
            int k = 0;
            while (k < 7) {
                array_with_result[k++] = array_with_result[k + 1];
            }
            array_with_result[k] = 0;
            preserv_result *= 10;
        }
    }

    if (result == 0) array_with_result[i++] = 0;

    if (this->count_equal <= 1) moveMemoryToLeft();
    convertToDigit(i, array_with_result, this->digitsOperand2, &this->digitsOperand2Count, &this->decimal_position2, result_decimal_position, &this->signal_digit_operand2, have_signal);
    showDigits(this->digitsOperand2, this->digitsOperand2Count, this->decimal_position2, have_signal);
    copyToMemory();

    // std::cout << "\nmemory_one: " << memory_one;
    // std::cout << "\nmemory_two: " << memory_two;
    if (this->count_equal <= 1) memory_two_free = true;
}