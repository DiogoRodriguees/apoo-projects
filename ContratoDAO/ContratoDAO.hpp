// #pragma once
#include "../Contrato/Contrato.hpp"

class ContratoDAO{
    Contrato *contratos[15];
    int novo = 0;

public:
    Contrato* Create();
    Contrato* Retrive();
    void Delete(Contrato*);
    void UpDate(Contrato*);
};