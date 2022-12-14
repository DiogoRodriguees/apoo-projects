// #pragma once
#include "../Contrato/Contrato.hpp"

class ContratoDAO{
    Contrato *contratos[15];
    int novo;

public:
    Contrato* Create();
    Contrato* Retrive(Professor* );
    void Delete(Contrato*);
    void UpDate(Contrato*);
};