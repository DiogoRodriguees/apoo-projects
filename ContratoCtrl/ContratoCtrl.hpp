#include "../Contrato/Contrato.hpp"

class ContratoCtrl{
    Contrato* contrato;

    public:
    void SetContratoCorrente();
    Contrato* GetContratoCorrente();
    void IniciarContrato(int);
    void DefinirPeriodoDoContrato(int, int);
};