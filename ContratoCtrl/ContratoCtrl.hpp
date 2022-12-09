#pragma once

#include "../ContratoDAO/ContratoDAO.hpp"
#include "../Contrato/Contrato.hpp"
#include "../ProfessorDAO/ProfessorDAO.hpp"

#define CLEAR_TERMINAL "clear"
class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    void IniciarContrato(int);
    void DefinirPeriodoDoContrato(char, char);
    void Confirmar();
    void InserirProfessor(Professor *, int);
};