
#include "../Turma/Turma.hpp"

class TurmaDAO{
    Turma *turmas[10];
    Turma *turmasModalidade[10];
    int countTurmas;

public:
    TurmaDAO();
    Turma *Create();
    Turma *Retrive(char *);
    void Delete();
    void update(Turma *);
    Turma **GetTurmas();
    Turma **GetTurmasPorModalidade(char*);
};