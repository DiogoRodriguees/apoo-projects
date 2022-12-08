#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include  <iostream>


void System::BootSystem(){
    bool systemLoad = true;

    while(systemLoad){
        std::cout << "\n\nBem Vindo\n";
        std::cout <<  "O que você deseja?\n";
        std::cout <<  "a - Matricular Aluno\n";
        std::cout <<  "b - Criar Turma\n";
        std::cout <<  "c - Contratar Funcionario\n";
        std::cout <<  "d - Sair\n";
        char opcao;
        std::cin >> opcao;
        switch(opcao){
            case 'a':
            break;
            case 'b':
            break;
            case 'c':
                this->IniciarContratoCtrl();
                this->FinalizarContratoCtrl();
            break;
            case 'd':
            systemLoad = false;
        }
    }
}

void System::IniciarContratoCtrl(){
    ContratoCtrl contratoCtrl;
    contratoCtrl.IniciarContrato(123);
}

void System::FinalizarContratoCtrl(){
    std::cout << "Contrato Finalizado com suceso";
}