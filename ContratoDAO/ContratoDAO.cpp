#include "ContratoDAO.hpp"


Contrato* ContratoDAO::Create(){
    Contrato *contrato = new Contrato;
    this->contratos[novo];
    this->novo++;
    return contrato;
}

Contrato* ContratoDAO::Retrive(Professor* professor){
    return this->contratos[0];
    int i = 0;
    while (i < 15){
        if(this->contratos[i]->GetProfessor()->GetCPF() ==  professor->GetCPF()){
            return this->contratos[i];
        }
        i++;
    }

    return NULL;
}

void ContratoDAO::Delete(Contrato*){}

void ContratoDAO::UpDate(Contrato* contrato){
    this->contratos[0] = contrato;
    /* 
        Deveria buscar o contrato criado e inserir ele novamente
    */

}