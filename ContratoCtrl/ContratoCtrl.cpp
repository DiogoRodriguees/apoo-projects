#include "ContratoCtrl.hpp"
#include <iostream>

ContratoCtrl::ContratoCtrl(){
    this->contratoDAO = new ContratoDAO;
}

void ContratoCtrl::IniciarContrato(int cpf){
    Contrato *contrato = this->contratoDAO->Create();
    this->SetContratoCorrente(contrato);
}

void ContratoCtrl::DefinirPeriodoDoContrato(int periodoInicio, int periodoTermino){
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

void ContratoCtrl::InserirProfessor(Professor* professor){
    Contrato *contrato = this->GetContratoCorrente();
    contrato->SetProfessor(professor);
}

void ContratoCtrl::SetContratoCorrente(Contrato *){}
Contrato *ContratoCtrl::GetContratoCorrente(){
    return this->contrato;
}

void ContratoCtrl::Confirmar(){
    


}