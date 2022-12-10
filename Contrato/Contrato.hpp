#pragma once
#include "../Professor/Professor.hpp"
#include <string.h>
class Contrato{
    char dataInicio[10];
    char dataTermino[10];

public:
    void SetPeriodoDeInicio(char*);
    void SetPeriodoDeTermino(char*);
    char* GetPeriodoDeInicio();
    char* GetPeriodoDeTermino();
    void SetProfessor(Professor *);
};