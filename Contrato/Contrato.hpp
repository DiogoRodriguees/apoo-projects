#pragma once
#include "../Professor/Professor.hpp"
#include "../Turma/Turma.hpp"

#include <string.h>
class Contrato{
    Professor *professor;
    char dataInicio[10];
    char dataTermino[10];
    Turma *turma;

public:
    void SetPeriodoDeInicio(char*);
    void SetPeriodoDeTermino(char*);
    char* GetPeriodoDeInicio();
    char* GetPeriodoDeTermino();
    void SetProfessor(Professor *);
    Professor * GetProfessor();
};