#include <iostream>
#include "./Calculator/Calculator.hpp"

/* Coloque aqui a referência para suas implementações */
#include "./Display/DisplayDiogo.hpp"
#include "./CPU/CpuDiogo.hpp"
#include "./Keyboard/KeyboardDiogo.hpp"
#include "./Key/KeyDiogo.hpp"


void testDisplay(Display& display) {
  std::cout << "Testing DISPLAY...\n";
  display.setSignal(NEGATIVE);
  display.addDigit(ZERO, true);
  display.addDigit(ZERO, true);
  display.clear();
  display.addDigit(ZERO);
  display.addDigit(ZERO);
  display.addDigit(ONE);
  display.addDigit(TWO);
  display.addDigit(THREE, true);
  display.addDigit(FOUR);
  display.addDigit(FIVE);
  display.addDigit(ZERO);
  display.addDigit(ONE);
}

void testCpu(Cpu& cpu) {
  std::cout << "Testing CPU...\n";
  /* Teste 1 */
  // cpu.receiveControl(ON_CLEAR_ERROR);
  // cpu.receiveDigit(ONE);
  // cpu.receiveDigit(TWO);
  // cpu.receiveControl(DECIMAL_SEPARATOR);
  // cpu.receiveDigit(THREE);
  // cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(FOUR);
  // cpu.receiveDigit(FIVE);
  // cpu.receiveControl(DECIMAL_SEPARATOR);
  // cpu.receiveDigit(SIX);
  // cpu.receiveOperation(EQUAL);

  /* Teste 2 */
  // cpu.receiveOperation(SUBTRACTION);
  // cpu.receiveDigit(EIGHT);
  // cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(FIVE);
  // cpu.receiveOperation(EQUAL);
  // cpu.receiveOperation(EQUAL);
  // cpu.receiveDigit(ONE);
  // cpu.receiveDigit(ZERO);
  // cpu.receiveOperation(EQUAL);
  /* -5 */

}

void testKeyboard(Keyboard& keyboard) {
  try {
    /* Teste 1 */
    // keyboard.findKey('1').press();
    // keyboard.findKey('2').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('3').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('4').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('6').press();
    // keyboard.findKey('=').press();
    /* 16.86 */

    /* Teste 2 */
    // keyboard.findKey('5').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('-').press();
    // keyboard.findKey('=').press();
    /* -5 */

    /* Teste 3 */
    // keyboard.findKey('1').press();
    // keyboard.findKey('2').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('3').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('4').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('6').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('4').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('6').press();
    // keyboard.findKey('=').press();
    /* 21.42 */

    /* Teste 4 */
    // keyboard.findKey('0').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('8').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    /* 3.8 */

    keyboard.findKey('1').press();
    keyboard.findKey('+').press();
    keyboard.findKey('1').press();
    keyboard.findKey('=').press();
    keyboard.findKey('a').press();
    keyboard.findKey('a').press();
    keyboard.findKey('r').press();
  }
  catch (const char* exception) {
    std::cerr << exception;
  }
}

int main(int argc, char** argv) {
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayDiogo d1;
  CpuDiogo c1;
  KeyboardDiogo kb1;

  KeyDiogo keyZero('0', ZERO);
  KeyDiogo keyOne('1', ONE);
  KeyDiogo keyTwo('2', TWO);
  KeyDiogo keyThree('3', THREE);
  KeyDiogo keyFour('4', FOUR);
  KeyDiogo keyFive('5', FIVE);
  KeyDiogo keySix('6', SIX);
  KeyDiogo keySeven('7', SEVEN);
  KeyDiogo keyEight('8', EIGHT);
  KeyDiogo keyNine('9', NINE);

  KeyDiogo keyAddition('+', ADDITION);
  KeyDiogo keySubtraction('-', SUBTRACTION);
  KeyDiogo keyDivision('/', DIVISION);
  KeyDiogo keyMultiplication('*', MULTIPLICATION);
  KeyDiogo keyEqual('=', EQUAL);
  KeyDiogo keyDecimalSeparator('.', DECIMAL_SEPARATOR);
  
  KeyDiogo keyOff('o', OFF);
  KeyDiogo KeyMemorySub('s', MEMORY_SUBTRACTION);
  KeyDiogo KeyMemoryAdd('a', MEMORY_ADDITION);
  KeyDiogo KeyMemoryReadClear('r', MEMORY_READ_CLEAR);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

  kb1.addKey(keyZero);
  kb1.addKey(keyOne);
  kb1.addKey(keyTwo);
  kb1.addKey(keyThree);
  kb1.addKey(keyFour);
  kb1.addKey(keyFive);
  kb1.addKey(keySix);
  kb1.addKey(keySeven);
  kb1.addKey(keyEight);
  kb1.addKey(keyNine);

  kb1.addKey(keyAddition);
  kb1.addKey(keySubtraction);
  kb1.addKey(keyDivision);
  kb1.addKey(keyMultiplication);
  kb1.addKey(keyEqual);
  kb1.addKey(keyDecimalSeparator);
  kb1.addKey(keyOff);
  kb1.addKey(KeyMemorySub);
  kb1.addKey(KeyMemoryAdd);
  kb1.addKey(KeyMemoryReadClear);

  // for (int i = 1;i < argc; i++) kb1.findKey(*argv[i]).press();
  
  /* Fase de testes */
  // testDisplay(d1);
  // testCpu(c1);
  testKeyboard(kb1);
}