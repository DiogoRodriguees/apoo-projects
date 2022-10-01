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

  // cpu.receiveOperation(SUBTRACTION);
  cpu.receiveDigit(EIGHT);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(FIVE);
  cpu.receiveOperation(EQUAL);
  cpu.receiveOperation(EQUAL);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(ZERO);
  cpu.receiveOperation(EQUAL);


  /* -5 */

}

void testKeyboard(Keyboard& keyboard) {
  try {
    keyboard.findKey('1').press();
    keyboard.findKey('+').press();
    keyboard.findKey('1').press();
    keyboard.findKey('=').press();
  }
  catch (const char* exception) {
    std::cerr << exception;
  }
}
/* Coloque aqui a referência para suas implementações */

int main() {
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayDiogo d1;
  CpuDiogo c1;
  KeyboardDiogo kb1;

  KeyDiogo keyZero('0', ONE);
  KeyDiogo keyOne('1', ONE);
  KeyDiogo keyTwo('2', TWO);
  KeyDiogo keyThree('3', THREE);
  KeyDiogo keyFour('4', THREE);
  KeyDiogo keyFive('5', THREE);
  KeyDiogo keySix('6', THREE);
  KeyDiogo keySeven('7', THREE);
  KeyDiogo keyEight('8', THREE);
  KeyDiogo keyNine('9', THREE);

  KeyDiogo keyAddition('+', ADDITION);
  KeyDiogo keySubtraction('-', SUBTRACTION);
  KeyDiogo keyDivision('/', DIVISION);
  KeyDiogo keyMultiplication('*', MULTIPLICATION);
  KeyDiogo keyEqual('=', EQUAL);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

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

  /* Fase de testes */
  // testDisplay(d1);
  testCpu(c1);
  // testKeyboard(kb1);
}