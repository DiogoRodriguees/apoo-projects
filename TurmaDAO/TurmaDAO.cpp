#include "TurmaDAO.hpp"

TurmaDAO::TurmaDAO(){
    this->countTurmas = 0;
    this->Create();
    Turma *turma = new Turma;
    Modalidade *modalidade = new Modalidade;
    Professor *professor = new Professor;
    turma->SetModalidade(modalidade);
    turma->SetNome("Turma A");
    turma->SetProfessor(professor);
    turma->SetDataInicio("20/03/2020");
    turma->SetDataTermino("20/03/2025");
    this->turmas[this->countTurmas++] = turma;
}

Turma *TurmaDAO::Create(){
    Turma *turma = new Turma;
    Modalidade *modalidade = new Modalidade;
    Professor *professor = new Professor;
    turma->SetModalidade(modalidade);
    turma->SetNome("Turma B");
    turma->SetProfessor(professor);
    turma->SetDataInicio("22/03/2022");
    turma->SetDataTermino("22/03/2024");
    this->turmas[this->countTurmas++] = turma;

    return turma;
}

Turma* TurmaDAO::Retrive(char*){
    /* buscar turma no vetor e retornar a tuma com a nome da modalidade recebida por parametro */
    return this->turmas[0];
}

Turma** TurmaDAO::GetTurmas(){
    /* buscar turma no vetor e retornar a tuma com a nome da modalidade recebida por parametro */
    return this->turmas;
}
void TurmaDAO::Delete(){}
void TurmaDAO::update(Turma*){}

