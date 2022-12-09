#pragma once
#include "../Professor/Professor.hpp"
class Contrato{
    char dataInicio[8];
    char dataTermino[8];

public:
    void SetPeriodoDeInicio(char);
    void SetPeriodoDeTermino(char);
    char* GetPeriodoDeInicio();
    char* GetPeriodoDeTermino();
    void SetProfessor(Professor *);
};