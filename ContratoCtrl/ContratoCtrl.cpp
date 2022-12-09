#include "ContratoCtrl.hpp"
#include <iostream>

void ContratoCtrl::IniciarContrato(int cpf){

}

void ContratoCtrl::DefinirPeriodoDoContrato(int periodoInicio, int periodoTermino){
    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}

void ContratoCtrl::Confirmar(Contrato* contrato){
    
}