#pragma once

#include "../ContratoDAO/ContratoDAO.hpp"
#include "../Contrato/Contrato.hpp"
#include "../ProfessorDAO/ProfessorDAO.hpp"
#include "../Modalidade/Modalidade.hpp"

#define CLEAR_TERMINAL "clear"
class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;
    ProfessorDAO *professorDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    void IniciarContrato(int);
    void DefinirPeriodoDoContrato(char*, char*);
    void Confirmar();
    void InserirModalidadesDoProfessor(Modalidade *, int); // alterar parametro 'professor' para 'modalidade'
};