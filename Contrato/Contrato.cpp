#include "Contrato.hpp"

void Contrato::SetPeriodoDeInicio(char* inicio){
    strcpy(this->dataInicio, inicio);
}

void Contrato::SetPeriodoDeTermino(char* termino){
    strcpy(this->dataInicio, termino);
}

char* Contrato::GetPeriodoDeInicio(){
    return this->dataInicio;
}
char* Contrato::GetPeriodoDeTermino(){
    return this->dataInicio;
}

void Contrato::SetProfessor(Professor* professor){
    this->professor = professor;
}

Professor*  Contrato::GetProfessor(){
    return this->professor;
}