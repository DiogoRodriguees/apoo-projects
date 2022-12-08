#include "System.h"
#include  <iostream>


void System::BootSystem(){
    std::cout << 'Bem Vindo\n';
    std::cout <<  "O que você deseja?\n";
    std::cout <<  "a - Matricular Aluno\n";
    std::cout <<  "b - Criar Turma\n";
    std::cout <<  "c - Contratar Funcionario\n";
    char opcao;
    std::cin >> opcao;
    std::cout << opcao << "opcao escolhida\n";
}