#include "TurmaDAO.hpp"

Turma *TurmaDAO::Create(){
    Turma *turma = new Turma;
    /* Adicionar turma ao vetor de turma */
    return turma;
}
Turma* TurmaDAO::Retrive(char*){
    /* buscar turma no vetor e retornar a tuma com a nome da modalidade recebida por parametro */
    return this->turmas[0];
}
void TurmaDAO::Delete(){}
void TurmaDAO::update(Turma*){}