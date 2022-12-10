#include "System.hpp"
#include <iostream>

void System::BootSystem()
{
    bool systemLoad = true;

    while (systemLoad)
    {
        system(CLEAR_TERMINAL);
        std::cout << "Bem Vindo\n";
        std::cout << "O que voce deseja?\n";
        std::cout << "1. Criar Turma\n";
        std::cout << "2. Matricular Aluno\n";
        std::cout << "3. Contratar Funcionario\n";
        std::cout << "4. Sair\n";

        char opcao;
        std::cin >> opcao;
        switch (opcao)
        {
            case '1': this->CriarTurma();
            break;

            case '2': this->MatricularAluno();
            break;

            case '3': this->ContratarFuncionario();
            break;

            case '4': systemLoad = false;
            break;
        }
    }
    system(CLEAR_TERMINAL);
}


void System::ContratarFuncionario()
{
    system(CLEAR_TERMINAL);
    std::cout << "Preenca os campos do contrato....\n";
    ContratoCtrl* contratoCtrl = new ContratoCtrl;

    int cpf;
    std::cout << "CPF: ";
    std::cin >> cpf;
    contratoCtrl->IniciarContrato(cpf);

    char inicio[10], fim[10];
    std::cout << "Data de Inicio: ";
    std::cin >> inicio;
    std::cout << "Data de Termino: ";
    std::cin >> fim;
    contratoCtrl->DefinirPeriodoDoContrato(inicio, fim);

    Modalidade* modalidades = new Modalidade;
    std::cout << "Informe as modalidade do contrato: \n";
    std::cout << "1. Boxe e Judo\n";
    std::cout << "2. Boxe\n";
    std::cout << "3. Judo\n";
    contratoCtrl->InserirModalidadesDoProfessor(modalidades, cpf);

    contratoCtrl->Confirmar();
}

void System::CriarTurma(){}
void System::MatricularAluno(){}
