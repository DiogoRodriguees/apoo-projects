#pragma once

#include "../ContratoDAO/ContratoDAO.hpp"
// #include "../ProfessorDAO/ProfessorDAO.hpp"
#include "../ModalidadeDAO/ModalidadeDAO.hpp"

#define CLEAR_TERMINAL "clear"
class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;
    ProfessorDAO *professorDAO;
    ModalidadeDAO *modalidadeDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    Modalidade** IniciarContrato(int, int*);
    void DefinirPeriodoDoContrato(char*, char*);
    void Confirmar();
    void InserirModalidadesDoProfessor(Modalidade *); // alterar parametro 'professor' para 'modalidade'
};