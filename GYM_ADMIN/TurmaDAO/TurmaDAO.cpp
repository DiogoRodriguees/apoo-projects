#include "TurmaDAO.hpp"
#include <iostream>

TurmaDAO::TurmaDAO(){
    this->countTurmas = 0;
    this->Create();
    Turma *turma = new Turma;
    Modalidade *modalidade = new Modalidade;
    modalidade->SetNome("Boxe");
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
    modalidade->SetNome("Judo");
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

Turma **TurmaDAO::GetTurmasPorModalidade(char* modalidade){
    int i = 0;
    int j = 0;

    while (i < this->countTurmas)
    {
        if(strcmp(modalidade,this->turmas[i]->GetModalidade()->GetNome())==  0){
            std::cout <<this->turmas[i]->GetModalidade()->GetNome() << " teste dentro da funcao  \n";
            this->turmasModalidade[j++] = this->turmas[i];
        }
        i++;
    }

    this->turmasModalidade[j] = NULL;

    return turmasModalidade;
}
