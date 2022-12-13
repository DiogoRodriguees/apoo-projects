#include "ContratoCtrl.hpp"

#include <iostream>


ContratoCtrl::ContratoCtrl(){
    contratoDAO = new ContratoDAO;
    this->professorDAO = new ProfessorDAO;
    this->modalidadeDAO = new ModalidadeDAO;
    this->turmaDAO = new TurmaDAO;
}

Modalidade** ContratoCtrl::IniciarContrato(int cpf, int *quantidadeDeModalidades){
    Contrato *contrato = GetContratoDAO()->Create();
    Professor *professor = GetProfessorDAO()->Retrive(cpf);

    if(professor == NULL){
        return 0;
    }

    contrato->SetProfessor(professor);
    this->SetContratoCorrente(contrato);

    *quantidadeDeModalidades = professor->GetQuantidadeModalidade();

    return professor->GetModalidades();
}

void ContratoCtrl::DefinirPeriodoDoContrato(char*periodoInicio, char*periodoTermino){
    Contrato *contrato = GetContratoCorrente();
    contrato->SetPeriodoDeInicio(periodoInicio);
    contrato->SetPeriodoDeTermino(periodoTermino);
}

Turma** ContratoCtrl::InserirModalidadesDoProfessor(Modalidade* modalidade, int* i){
    Contrato *contrato = GetContratoCorrente();
    TurmaDAO *turmaDAO = GetTurmaDAO();
    contrato->SetModalidade(modalidade);

    return turmaDAO->GetTurmasPorModalidade(modalidade->GetNome());
}

void ContratoCtrl::Confirmar(){
    Contrato *contrato = GetContratoCorrente();

    system(CLEAR_TERMINAL);
    std::cout << "Informacoes do Contrato\n\n";
    std::cout << "* Data de Inicio : " << contrato->GetPeriodoDeInicio() << "\n";
    std::cout << "* Data de Termino: " << contrato->GetPeriodoDeTermino() << "\n";
    std::cout << "* Data de Recisao: " << "\n\n";
    std::cout << "* Turma..........: ";
    std::cout << contrato->GetTurma()->GetNome() << "   ";
    std::cout << contrato->GetTurma()->GetDataInicio() << "   ";
    std::cout << contrato->GetTurma()->GetDataTermino() << "   ";
    std::cout << contrato->GetTurma()->GetModalidade()->GetNome() << "   \n";
    std::cout << "* Modalidade.....: " << contrato->GetModalidade()->GetNome()  << "\n";
    std::cout << "* Nome do Professor: " << contrato->GetProfessor()->GetNome()  << "\n";
    std::cout << "\nConfirmar informacoes do contrato? (s)sim (n)nao ";
    
    char confirma;
    std::cin >> confirma;

    if(confirma != 's'){
        contrato = NULL;
    }
}

void ContratoCtrl::SetContratoCorrente(Contrato *contrato){
    this->contrato = contrato;
}

Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}

void ContratoCtrl::InserirTurma(Turma *turma){
    contrato->SetTurma(turma);
}

ContratoDAO *ContratoCtrl::GetContratoDAO(){
    return this->contratoDAO;
}

ProfessorDAO *ContratoCtrl::GetProfessorDAO(){
    return this->professorDAO;
}

ModalidadeDAO *ContratoCtrl::GetModalidadeDAO(){
    return this->modalidadeDAO;
}

TurmaDAO *ContratoCtrl::GetTurmaDAO(){
    return this->turmaDAO;

}