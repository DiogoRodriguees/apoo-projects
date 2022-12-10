#pragma once
#include "../ContratoCtrl/ContratoCtrl.hpp"

class System{
    ContratoCtrl *contratoCtrl;

public:
    System();
    void ContratarFuncionario();
    void MatricularAluno();
    void CriarTurma();
    void BootSystem();
};