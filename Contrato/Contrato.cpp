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

void Contrato::SetProfessor(Professor* professor_recebido){
    this->professor = professor_recebido;
}

Professor*  Contrato::GetProfessor(){
    return this->professor;
}

Modalidade *Contrato::GetModalidade(){
    return this->modalidade;
}
void Contrato::SetModalidade(Modalidade *modalidade){
    this->modalidade = modalidade;
}