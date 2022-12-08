#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include  <iostream>


void System::BootSystem(){
    bool systemLoad = true;

    while(systemLoad){
        std::cout << "\n\nBem Vindo\n";
        std::cout <<  "O que voce deseja?\n";
        std::cout <<  "A. Matricular Aluno\n";
        std::cout <<  "B. Criar Turma\n";
        std::cout <<  "C. Contratar Funcionario\n";
        std::cout <<  "D. Sair\n";
        char opcao;
        std::cin >> opcao;
        switch(opcao){
            case 'a':
            break;
            case 'b':
            break;
            case 'c':
            system("cls");
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
    std::cout << "Informe o CPF do Professor a ser contratado\n";
    int cpf;    
    std::cin >> cpf;
    contratoCtrl.IniciarContrato(cpf);
}

void System::FinalizarContratoCtrl(){

    std::cout << "Deseja Finalizar o Processor? (s)sim (n)nao";
    std::cout << "Contrato Finalizado com suceso";
}