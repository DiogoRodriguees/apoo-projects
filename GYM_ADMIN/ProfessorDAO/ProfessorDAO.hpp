#include "../Professor/Professor.hpp"

class ProfessorDAO{
    Professor *professores[10];
    int countProfessor;

public:
    ProfessorDAO();
    Professor *Retrive(int); // parametro int representando CPF do professor
};