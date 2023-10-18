#pragma once
#include "../TurmaDAO/TurmaDAO.hpp"

#include <string.h>
class Contrato{
    Professor *professor;
    char dataInicio[15];
    char dataTermino[15];
    Turma *turma;
    Modalidade *modalidade;

public:
    void SetPeriodoDeInicio(char*);
    void SetPeriodoDeTermino(char*);
    char* GetPeriodoDeInicio();
    char* GetPeriodoDeTermino();
    void SetProfessor(Professor *);
    Professor * GetProfessor();
    Modalidade *GetModalidade();
    void SetModalidade(Modalidade *);
    void SetTurma(Turma*);
    Turma *GetTurma();
};