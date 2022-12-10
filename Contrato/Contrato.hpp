#pragma once
#include "../Turma/Turma.hpp"

#include <string.h>
class Contrato{
    Professor *professor;
    char dataInicio[10];
    char dataTermino[10];
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
};