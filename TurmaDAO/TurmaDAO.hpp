
#include "../Turma/Turma.hpp"

class TurmaDAO{
    Turma *turmas[10];
    int countTurmas;

public:
    TurmaDAO();
    Turma *Create();
    Turma *Retrive(char *);
    void Delete();
    void update(Turma *);
};