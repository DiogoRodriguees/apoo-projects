#include "../Contrato/Contrato.hpp"
#include "../ContratoDAO/ContratoDAO.hpp"

class ContratoCtrl{
    Contrato* contrato;
    ContratoDAO *contratoDAO;

public:
    ContratoCtrl();
    void SetContratoCorrente(Contrato *);
    Contrato *GetContratoCorrente();
    void IniciarContrato(int);
    void DefinirPeriodoDoContrato(int, int);
    void Confirmar();
    void InserirProfessor(Professor *);
};