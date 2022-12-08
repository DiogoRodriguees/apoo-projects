#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include <iostream>

void System::BootSystem()
{
    bool systemLoad = true;

    while (systemLoad)
    {
        std::cout << "\n\nBem Vindo\n";
        std::cout << "O que voce deseja?\n";
        std::cout << "1. Matricular Aluno\n";
        std::cout << "2. Criar Turma\n";
        std::cout << "3. Contratar Funcionario\n";
        std::cout << "0. Sair\n";
        char opcao;
        std::cin >> opcao;
        switch (opcao)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            system("cls");
            this->IniciarContratoCtrl();
            this->FinalizarContratoCtrl();
            break;
        case '0':
            systemLoad = false;
        }
    }
}

void System::IniciarContratoCtrl()
{
    ContratoCtrl contratoCtrl;
    std::cout << "Informe o CPF do Professor a ser contratado\n";
    int cpf;
    std::cin >> cpf;
    contratoCtrl.IniciarContrato(cpf);
}

void System::FinalizarContratoCtrl()
{

    std::cout << "Deseja Finalizar o Processor? (s)sim (n)nao";
    std::cout << "Contrato Finalizado com suceso";
}