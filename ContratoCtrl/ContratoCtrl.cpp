#include "ContratoCtrl.hpp"
#include "../Contrato/Contrato.hpp"

#include <iostream>


ContratoCtrl::ContratoCtrl(){
    this->contratoDAO = new ContratoDAO;
    this->professorDAO = new ProfessorDAO;
}

void ContratoCtrl::IniciarContrato(int cpf){
    Contrato *contrato = this->contratoDAO->Create();

    Professor *professor = this->professorDAO->Retrive(cpf);
    this->SetContratoCorrente(contrato);
    this->contrato->SetProfessor(professor);

}

void ContratoCtrl::DefinirPeriodoDoContrato(char*periodoInicio, char*periodoTermino){
    system(CLEAR_TERMINAL);
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

void ContratoCtrl::InserirModalidadesDoProfessor(Modalidade* modalidade, int cpf){

}

void ContratoCtrl::Confirmar(){
    std::cout << "Informacoes do Contrato\n";
    std::cout << "Data de Inicio : " << this->contrato->GetPeriodoDeInicio() << "\n";
    std::cout << "Data de Termino: " << this->contrato->GetPeriodoDeTermino() << "\n";
    std::cout << "Nome do Professor   : " << this->contrato->GetProfessor()->GetNome()  << "\n";
    std::cout << "Salario do Professor: " << this->contrato->GetProfessor()->GetSalario()  << "\n";
    std::cout << "\nConfirmar informacoes do contrato? (s)sim (n)nao ";
    
    char confirma;
    std::cin >> confirma;
}

void ContratoCtrl::SetContratoCorrente(Contrato *contrato){
    this->contrato = contrato;
}

Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}