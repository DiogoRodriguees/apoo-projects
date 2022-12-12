#include "Turma.hpp"
#include <string.h>

void Turma::SetModalidade(Modalidade* modalidade){
    this->modalidade = modalidade;
}
Modalidade* Turma::GetModalidade(){
    return this->modalidade;
}

void Turma::SetDataInicio(char* dataInicio){
   strcpy(this->dataInicio, dataInicio);
}
char* Turma::GetDataInicio(){
   return this->dataInicio;
}

void Turma::SetDataTermino(char* dataTermino){
   strcpy(this->dataTermino, dataTermino);
}

char* Turma::GetDataTermino(){
   return this->dataTermino;
}

void Turma::SetProfessor(Professor *professor){
   this->professor = professor;
}

Professor* Turma::GetProfessor(){
   return this->professor;
}

void Turma::SetNome(char *nome){
   strcpy( this->nome, nome);
}
char* Turma::GetNome(){
   return this->nome;
}
