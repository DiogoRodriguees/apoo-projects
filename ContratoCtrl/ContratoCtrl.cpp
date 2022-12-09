#include "ContratoCtrl.hpp"
#include <iostream>


ContratoCtrl::ContratoCtrl(){
    this->contratoDAO = new ContratoDAO;
}

void ContratoCtrl::IniciarContrato(){
    Contrato *contrato = this->contratoDAO->Create();
    this->SetContratoCorrente(contrato);
}

void ContratoCtrl::DefinirPeriodoDoContrato(char periodoInicio, char periodoTermino){
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

void ContratoCtrl::InserirProfessor(Professor* professor, int cpf){
    this->contrato->SetProfessor(professor);
}

void ContratoCtrl::Confirmar(){
    // std::cout << this->contrato->GetPeriodoDeInicio() << "\n";
    // std::cout << this->contrato->GetPeriodoDeTermino() << "\n";
    std::cout << "\nFinzalizar contrato? (s)sim (n)nao ";
    char confirma;
    std::cin >> confirma;
}

void ContratoCtrl::SetContratoCorrente(Contrato *){}
Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}