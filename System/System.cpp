#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include <iostream>

void System::BootSystem()
{
    bool systemLoad = true;

    while (systemLoad)
    {
        system("cls");
        std::cout << "Bem Vindo\n";
        std::cout << "O que voce deseja?\n";
        std::cout << "1. Matricular Aluno\n";
        std::cout << "2. Criar Turma\n";
        std::cout << "3. Contratar Funcionario\n";
        std::cout << "0. Sair\n";

        char opcao;
        std::cin >> opcao;
        switch (opcao)
        {
            case '1': this->MatricularAluno();
            break;

            case '2': this->CriarTurma();
            break;

            case '3': this->ContratarFuncionario();
            break;

            case '0': systemLoad = false;
            break;
        }
    }
    system("cls");
}


void System::ContratarFuncionario()
{
    system("cls");
    ContratoCtrl contratoCtrl;

    int cpf;
    contratoCtrl.IniciarContrato(cpf);

    int inicio, fim;
    contratoCtrl.DefinirPeriodoDoContrato(inicio, fim);

    Professor professor;
    contratoCtrl.InserirProfessor(&professor);

    contratoCtrl.Confirmar();
}

void System::CriarTurma(){}
void System::MatricularAluno(){}
