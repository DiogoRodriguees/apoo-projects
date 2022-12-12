#include "System.hpp"
#include <iostream>
#include <stdio.h>

System::System(){
    this->contratoCtrl = new ContratoCtrl;
}

char MsgBootSystem();
int MsgIniciarContrato();
void MsgDefinirPeriodoDoContrato(char *inicio, char *termino);
Modalidade *MsgInserirModalidadesDoProfessor(int qtdeModalidades, Modalidade** modalidades);
Turma* MsgInseriTurma(Turma** turmas);

void System::CriarTurma(){}
void System::MatricularAluno(){}

void System::BootSystem(){
    bool systemLoad = true;

    while (systemLoad){ 
        switch (MsgBootSystem()){
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
    int cpf, i;
    char inicio[10], termino[10];

    cpf = MsgIniciarContrato();
    Modalidade **modalidades = this->contratoCtrl->IniciarContrato(cpf, &i);

    MsgDefinirPeriodoDoContrato(inicio, termino);
    this->contratoCtrl->DefinirPeriodoDoContrato(inicio, termino);

    Modalidade *modalidade = MsgInserirModalidadesDoProfessor(i, modalidades);
    Turma** turmas = this->contratoCtrl->InserirModalidadesDoProfessor(modalidade, &i);

    Turma* turma  = MsgInseriTurma(turmas);
    this->contratoCtrl->InserirTurma(turma);
    this->contratoCtrl->Confirmar();
}

/*************************************************
*             Mensagens - Boot System            *              
**************************************************/
char MsgBootSystem(){
    system(CLEAR_TERMINAL);
        
    std::cout << "Bem Vindo\n";
    std::cout << "O que voce deseja\n";
    std::cout << "1. Criar Turma\n";
    std::cout << "2. Matricular Aluno\n";
    std::cout << "3. Contratar Funcionario\n";
    std::cout << "4. Sair\n";

    char opcao;
    std::cin >> opcao;
    system(CLEAR_TERMINAL);

    return opcao;
}

/*************************************************
*       Mensagens - Contratar Funcionario        *              
**************************************************/
int MsgIniciarContrato(){
    int cpf;
    std::cout << "Preenca os campos do contrato....\n";
    std::cout << "CPF: ";
    std::cin >> cpf;

    return cpf;
}

void MsgDefinirPeriodoDoContrato(char* inicio, char* termino){
    std::cout << "Data de Inicio: ";
    std::cin >> inicio;
    std::cout << "Data de Termino: ";
    std::cin >> termino;
}

Modalidade *MsgInserirModalidadesDoProfessor(int qtdeModalidades, Modalidade** modalidades){
    int j = 0;
    system(CLEAR_TERMINAL);
    std::cout << "Informe as modalidade do contrato: \n";
    while(j < qtdeModalidades){
        std::cout << j+ 1 << ". "<< modalidades[j++]->GetNome() << "\n";
    }
    std::cin >> j;
    return modalidades[j - 1];
}

Turma*  MsgInseriTurma(Turma** turmas){
    int i = 0;
    system(CLEAR_TERMINAL);
    std::cout << "Informe a turma do contrato.....\n   ";
    std::cout << "Nome      ";
    std::cout << "Data de Inicio      ";
    std::cout << "Data de Termino\n";

    while(turmas[i] != NULL){
        std::cout << i + 1 << ". " << turmas[i]->GetNome() << "   ";
        std::cout << turmas[i]->GetDataInicio() << "          ";
        std::cout << turmas[i]->GetDataTermino() << "\n";
        i++;
    }

    std::cin >> i;
    return turmas[i - 1];
}
