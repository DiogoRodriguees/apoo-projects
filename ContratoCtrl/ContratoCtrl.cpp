#include "ContratoCtrl.hpp"

#include <iostream>


ContratoCtrl::ContratoCtrl(){
    this->contratoDAO = new ContratoDAO;
    this->professorDAO = new ProfessorDAO;
    this->modalidadeDAO = new ModalidadeDAO;
    this->turmaDAO = new TurmaDAO;
}

Modalidade** ContratoCtrl::IniciarContrato(int cpf, int *quantidadeDeModalidades){
    Contrato *contrato = this->contratoDAO->Create();
    Professor *professor = this->professorDAO->Retrive(cpf);

    if(professor == NULL){
        return 0;
    }

    contrato->SetProfessor(professor);
    this->SetContratoCorrente(contrato);

    *quantidadeDeModalidades = professor->GetQuantidadeModalidade();

    return professor->GetModalidades();
}

void ContratoCtrl::DefinirPeriodoDoContrato(char*periodoInicio, char*periodoTermino){
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

Turma** ContratoCtrl::InserirModalidadesDoProfessor(Modalidade* modalidade, int* i){
    this->contrato->SetModalidade(modalidade);

    return turmaDAO->GetTurmasPorModalidade(modalidade->GetNome());
}

void ContratoCtrl::Confirmar(){
    system(CLEAR_TERMINAL);
    std::cout << "Informacoes do Contrato\n\n";
    std::cout << "* Data de Inicio : " << this->contrato->GetPeriodoDeInicio() << "\n";
    std::cout << "* Data de Termino: " << this->contrato->GetPeriodoDeTermino() << "\n";
    std::cout << "* Data de Recisao: " << "\n\n";
    std::cout << "* Turma..........: ";
    std::cout << this->contrato->GetTurma()->GetNome() << "   ";
    std::cout << this->contrato->GetTurma()->GetDataInicio() << "   ";
    std::cout << this->contrato->GetTurma()->GetDataTermino() << "   ";
    std::cout << this->contrato->GetTurma()->GetModalidade()->GetNome() << "   \n";
    std::cout << "* Modalidade.....: " << this->contrato->GetModalidade()->GetNome()  << "\n";
    std::cout << "* Nome do Professor: " << this->contrato->GetProfessor()->GetNome()  << "\n";
    std::cout << "\nConfirmar informacoes do contrato? (s)sim (n)nao ";
    
    char confirma;
    std::cin >> confirma;

    if(confirma != 's'){
        this->contrato = NULL;
    }
}

void ContratoCtrl::SetContratoCorrente(Contrato *contrato){
    this->contrato = contrato;
}

Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}

void ContratoCtrl::InserirTurma(Turma *turma){
    this->contrato->SetTurma(turma);
}