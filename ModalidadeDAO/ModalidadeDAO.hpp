#include "../Modalidade/Modalidade.hpp"

class ModalidadeDAO{
    public:
        Modalidade* Create();
        void Retrive(char*);
        void Update(Modalidade*);
        void Delete(char*);
};