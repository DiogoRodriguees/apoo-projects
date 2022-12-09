#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include <iostream>

void System::BootSystem()
{
    bool systemLoad = true;

    while (systemLoad)
    {
        system("cls");
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
}


void System::ContratarFuncionario()
{
    system("cls");
    ContratoCtrl contratoCtrl;

    int cpf;
    std::cout << "Informe o CPF do Professor a ser contratado: ";
    std::cin >> cpf;
    contratoCtrl.IniciarContrato(cpf);

    int inicio, fim;
    std::cout << "Informe a data de inicio: ";
    std::cin >> inicio;
    std::cout << "Informe a  data de Termino: ";
    std::cin >> fim;
    contratoCtrl.DefinirPeriodoDoContrato(inicio, fim);

    int formacoes[5];
    std::cout << "Informe as formacoes do professor: \n";
    std::cout << "1. Boxe\n";
    std::cout << "2. Jiu Jitsu\n";
    std::cout << "3. Muay Thai\n";
    std::cin >> formacoes[0];

}

void System::CriarTurma(){}
void System::MatricularAluno(){}
