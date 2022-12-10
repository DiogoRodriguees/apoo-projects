#pragma once
#include "../Professor/Professor.hpp"
#include <string.h>
class Contrato{
    Professor *professor;
    char dataInicio[10];
    char dataTermino[10];

public:
    void SetPeriodoDeInicio(char*);
    void SetPeriodoDeTermino(char*);
    char* GetPeriodoDeInicio();
    char* GetPeriodoDeTermino();
    void SetProfessor(Professor *);
    Professor * GetProfessor();
};