#pragma once

#include "../ContratoDAO/ContratoDAO.hpp"
// #include "../ProfessorDAO/ProfessorDAO.hpp"
#include "../ModalidadeDAO/ModalidadeDAO.hpp"
// #include "../TurmaDAO/TurmaDAO.hpp"
#define CLEAR_TERMINAL "clear"
class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;
    ProfessorDAO *professorDAO;
    ModalidadeDAO *modalidadeDAO;
    TurmaDAO *turmaDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    Modalidade** IniciarContrato(int, int*);
    void DefinirPeriodoDoContrato(char*, char*);
    void Confirmar();
    Turma** InserirModalidadesDoProfessor(Modalidade *, int*); // alterar parametro 'professor' para 'modalidade'
    void InserirTurma(Turma *); // alterar parametro 'professor' para 'modalidade'
    ContratoDAO *GetContratoDAO();
    ProfessorDAO *GetProfessorDAO();
    ModalidadeDAO *GetModalidadeDAO();
    TurmaDAO *GetTurmaDAO();
    void ExibirContrato(int);
};