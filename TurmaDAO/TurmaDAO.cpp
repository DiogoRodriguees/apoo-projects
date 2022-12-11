#include "TurmaDAO.hpp"

TurmaDAO::TurmaDAO(){
    this->countTurmas = 0;
}

Turma *TurmaDAO::Create(){
    Turma *turma = new Turma;
    Modalidade *modalidade = new Modalidade;
    Professor *professor = new Professor;
    turma->SetModalidade(modalidade);
    turma->SetProfessor(professor);
    turma->SetDataInicio("22032022");
    turma->SetDataTermino("22032024");
    this->turmas[this->countTurmas++] = turma;

    return turma;
}

Turma* TurmaDAO::Retrive(char*){
    /* buscar turma no vetor e retornar a tuma com a nome da modalidade recebida por parametro */
    return this->turmas[0];
}
void TurmaDAO::Delete(){}
void TurmaDAO::update(Turma*){}