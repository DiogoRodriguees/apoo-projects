#include "../Contrato/Contrato.h"

class ContratoCtrl{
    public:
        void SetContratoCorrente();
        Contrato GetContratoCorrente();
        void IniciarContrato(int);
        void DefinirPeriodoDoContrato(int, int);// modificar parametro int
        
};