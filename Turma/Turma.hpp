#include "../Modalidade/Modalidade.hpp"
#include "../Professor/Professor.hpp"

class Turma{
    Modalidade* modalidade;
    char dataInici[10];
    char dataTermino[10];
    Professor *professor;
    
public:
    void SetModalidade(Modalidade*);
    Modalidade* GetModalidade(char*);
};