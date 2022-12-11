#include "System.hpp"
#include <iostream>
#include <stdio.h>

System::System()
{
    this->contratoCtrl = new ContratoCtrl;
}

void MsgDefinirPeriodoDoContrato(char *inicio, char *termino);
Modalidade *MsgInserirModalidadesDoProfessor(int qtdeModalidades, Modalidade** modalidades);

void System::CriarTurma(){}
void System::MatricularAluno(){}

void System::BootSystem(){
    bool systemLoad = true;
    while (systemLoad)
    {
        system(CLEAR_TERMINAL);
        std::cout << "Bem Vindo\n";
        std::cout << "O que voce de";
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

    int cpf,i;
    std::cout << "CPF: ";
    std::cin >> cpf;
    Modalidade **modalidades = this->contratoCtrl->IniciarContrato(cpf, &i);

    char inicio[10], termino[10];
    MsgDefinirPeriodoDoContrato(inicio, termino);
    this->contratoCtrl->DefinirPeriodoDoContrato(inicio, termino);

    Modalidade *modalidade = MsgInserirModalidadesDoProfessor(i, modalidades);
    this->contratoCtrl->InserirModalidadesDoProfessor(modalidade);

    this->contratoCtrl->Confirmar();
}



void MsgDefinirPeriodoDoContrato(char* inicio, char* termino){
    std::cout << "Data de Inicio: ";
    std::cin >> inicio;
    std::cout << "Data de Termino: ";
    std::cin >> termino;
}

Modalidade *MsgInserirModalidadesDoProfessor(int qtdeModalidades, Modalidade** modalidades){
    int j = 0;
    std::cout << "Informe as modalidade do contrato: \n";
    while(j < qtdeModalidades){
        std::cout << j+ 1 << ". "<< modalidades[j++]->GetNome() << "\n";
    }
    std::cin >> j;
    return modalidades[j - 1];
}