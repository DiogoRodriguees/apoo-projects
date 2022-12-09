#include "../ContratoDAO/ContratoDAO.hpp"

#define CLEAR_TERMINAL "clear"
class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    void IniciarContrato();
    void DefinirPeriodoDoContrato(char, char);
    void Confirmar();
    void InserirProfessor(Professor *, int);
};