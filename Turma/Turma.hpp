// #include "../Modalidade/Modalidade.hpp"
#include "../Professor/Professor.hpp"

class Turma{
    Modalidade* modalidade;
    char dataInicio[10];
    char dataTermino[10];
    Professor *professor;
    
public:
    void SetModalidade(Modalidade*);
    Modalidade* GetModalidade();

    void SetDataInicio(char*);
    char* GetDataInicio();

    void SetDataTermino(char*);
    char* GetDataTermino();

    void SetProfessor(Professor *);
    Professor* GetProfessor();
};