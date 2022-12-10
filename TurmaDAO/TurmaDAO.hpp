
#include "../Turma/Turma.hpp"

class TurmaDAO{
    Turma *turmas[10];

public:
    Turma *Create();
    Turma *Retrive(char *);
    void Delete();
    void update(Turma *);
};