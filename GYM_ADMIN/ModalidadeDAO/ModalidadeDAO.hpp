// #include "../Modalidade/Modalidade.hpp"
#include "../ProfessorDAO/ProfessorDAO.hpp"

class ModalidadeDAO{
    Modalidade* modalidades[10];
    int quantidadeModalidade;

public:
    ModalidadeDAO();
    Modalidade *Create(char*);
    Modalidade* Retrive(char *);
    void Update(Modalidade *);
    void Delete(char *);
    Modalidade **GetModalidades();
};