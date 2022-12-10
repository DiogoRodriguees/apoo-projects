#include "ModalidadeDAO.hpp"
#include <string.h>

ModalidadeDAO::ModalidadeDAO(){
    this->quantidadeModalidade = 0;
    this->Create("Boxe");
    this->Create("Judo");
    this->Create("Muay Tai");
    this->Create("Crossfit");
}

Modalidade **ModalidadeDAO::GetModalidades()
{
    return this->modalidades;
}

Modalidade* ModalidadeDAO::Create(char*nome){
    Modalidade *modalidade = new Modalidade;
    modalidade->SetNome(nome);
    this->modalidades[this->quantidadeModalidade++];
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

