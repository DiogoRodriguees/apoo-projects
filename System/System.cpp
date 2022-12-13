#include "System.hpp"
#include <iostream>
#include <stdio.h>

/**************************************************
*                   Construtor                    *
***************************************************/
System::System(){
    this->contratoCtrl = new ContratoCtrl;
}

/**************************************************
*        Mensagens - Contratar Funcionario        *              
***************************************************/
int MsgIniciarContrato();
char MsgBootSystem();
void MsgDefinirPeriodoDoContrato(char *inicio, char *termino);
Turma* MsgInseriTurma(Turma** turmas);
Modalidade *MsgInserirModalidadesDoProfessor(int qtdeModalidades, Modalidade** modalidades);

/**************************************************
*                  Implementação                  *
***************************************************/
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
    ContratoCtrl *contratoCtrl = GetContratoCtrl();

    cpf = MsgIniciarContrato();
    if(cpf == 0) return;
    Modalidade **modalidades = contratoCtrl->IniciarContrato(cpf, &i);

    MsgDefinirPeriodoDoContrato(inicio, termino);
    contratoCtrl->DefinirPeriodoDoContrato(inicio, termino);

    std::cout << "\nTudo ok\n";
    Modalidade *modalidade = MsgInserirModalidadesDoProfessor(i, modalidades);
    Turma **turmas = contratoCtrl->InserirModalidadesDoProfessor(modalidade, &i);

    Turma* turma  = MsgInseriTurma(turmas);
    contratoCtrl->InserirTurma(turma);
    contratoCtrl->Confirmar();
}

void System::CriarTurma(){}
void System::MatricularAluno(){}

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

/**************************************************
*      Mensagens - U.C Contratar Funcionario      *              
***************************************************/
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
    system(CLEAR_TERMINAL);
    std::cout << "Informe as modalidade do contrato: \n";
    
    int j = 0;
    while(j < qtdeModalidades) std::cout << j+ 1 << ". "<< modalidades[j++]->GetNome() << "\n";

    std::cin >> j;

    return modalidades[j - 1];
}

Turma*  MsgInseriTurma(Turma** turmas){
    int i = 0;

    system(CLEAR_TERMINAL);
    std::cout << "Informe a turma do contrato.....\n   ";
    std::cout << "Nome      ";
    std::cout << "Data de Inicio      ";
    std::cout << "Data de Termino   ";
    std::cout << "Modalidade \n";

    while(turmas[i] != NULL){
        std::cout << i + 1 << ". " << turmas[i]->GetNome() << "   ";
        std::cout << turmas[i]->GetDataInicio() << "          ";
        std::cout << turmas[i]->GetDataTermino() << "        ";
        std::cout << turmas[i]->GetModalidade()->GetNome() << "   \n";

        i++;
    }

    std::cin >> i;
    return turmas[i - 1];
}

ContratoCtrl* System::GetContratoCtrl(){
    return this->contratoCtrl;
}
