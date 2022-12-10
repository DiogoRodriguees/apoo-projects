#include "ContratoDAO.hpp"


Contrato* ContratoDAO::Create(){
    Contrato *contrato = new Contrato;
    this->contratos[novo];
    this->novo++;
    return contrato;
}

Contrato* ContratoDAO::Retrive(){
    Contrato *contrato = new Contrato;
    return contrato;
}

void ContratoDAO::Delete(Contrato*){}

void ContratoDAO::UpDate(Contrato* contrato){
    int i = 0;
    while (i < 15){
        if(this->contratos[i] = contrato){
            this->contratos[i] = contrato;
        }
    }
}