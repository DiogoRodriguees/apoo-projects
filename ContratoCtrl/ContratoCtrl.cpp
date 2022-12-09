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

void ContratoCtrl::Confirmar(){
    
}

void ContratoCtrl::InserirProfessor(Professor*){}