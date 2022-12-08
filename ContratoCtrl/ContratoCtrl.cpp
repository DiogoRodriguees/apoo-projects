#include "ContratoCtrl.hpp"
#include <iostream>


void ContratoCtrl::IniciarContrato(int cpf){

}

void ContratoCtrl::DefinirPeriodoDoContrato(){
    std::cout <<  "Insira o Periodo do Contrato\n";
    int periodoInicio;
    int periodoTermino;
    std::cin >> periodoInicio;
    std::cin >> periodoTermino;

    this->contrato->SetPeriodoDeInicio(periodoInicio);
    this->contrato->SetPeriodoDeTermino(periodoTermino);
}