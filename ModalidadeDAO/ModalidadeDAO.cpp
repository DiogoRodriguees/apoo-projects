#include "ModalidadeDAO.hpp"
#include <string.h>

ModalidadeDAO::ModalidadeDAO(){
    this->quantidadeModalidade = 0;
    Modalidade *modalidade1 = new Modalidade;
    Modalidade *modalidade2 = new Modalidade;
    char nome1[5] = "Boxe";
    char nome2[5] = "Judo";
    modalidade1->SetNome(nome1);
    modalidade2->SetNome(nome2);

    this->modalidades[0] = modalidade1;
    this->modalidades[1] = modalidade2;
    this->quantidadeModalidade = 2;
}

Modalidade **ModalidadeDAO::GetModalidades()
{
    return this->modalidades;
}

Modalidade* ModalidadeDAO::Create(){
    /* Adicionar modalidade ao vetor de modalidades */

    Modalidade *modalidade = new Modalidade;
    return modalidade;
}

Modalidade* ModalidadeDAO::Retrive(char* nome){
    int i = 0;

    while(i < this->quantidadeModalidade){
        if(strcmp(nome,this->modalidades[i]->GetNome()) == 0){
            return this->modalidades[i];
        }
    }
    return this->modalidades[0];
}
void ModalidadeDAO::Update(Modalidade* modalidade){}
void ModalidadeDAO::Delete(char* nome){}

