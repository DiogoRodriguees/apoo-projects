#include "Turma.hpp"

void Turma::SetModalidade(Modalidade* modalidade){
    this->modalidade = modalidade;
}
Modalidade* Turma::GetModalidade(char*){
    return this->modalidade;
}