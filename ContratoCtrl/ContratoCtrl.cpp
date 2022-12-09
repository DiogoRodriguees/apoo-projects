#include "ContratoCtrl.hpp"
#include "../Contrato/Contrato.hpp"

#include <iostream>


ContratoCtrl::ContratoCtrl(){
    this->contratoDAO = new ContratoDAO;
}

void ContratoCtrl::IniciarContrato(int cpf){
    Contrato *contrato = this->contratoDAO->Create();
    this->SetContratoCorrente(contrato);

    ProfessorDAO *professorDAO = new ProfessorDAO;
    Professor *professor = professorDAO->Retrive(cpf);
}

void ContratoCtrl::DefinirPeriodoDoContrato(char*periodoInicio, char*periodoTermino){
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

void ContratoCtrl::InserirProfessor(Professor* professor, int cpf){
    this->contrato->SetProfessor(professor);
}

void ContratoCtrl::Confirmar(){
    std::cout << this->contrato->GetPeriodoDeInicio() << "\n";
    std::cout << this->contrato->GetPeriodoDeTermino() << "\n";
    std::cout << "\nFinzalizar contrato? (s)sim (n)nao ";
    char confirma;
    std::cin >> confirma;
}

void ContratoCtrl::SetContratoCorrente(Contrato *contrato){}
Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}