#include "ModalidadeDAO.hpp"
#include <string.h>

ModalidadeDAO::ModalidadeDAO(){
    this->quantidadeModalidade = 0;
    Modalidade *modalidade1 = new Modalidade;
    Modalidade *modalidade2 = new Modalidade;
    char nome1[5] = "Boxe";
    char nome2[5] = "Judo";
    char nome3[10] = "MuayTai";
    char nome4[10] = "Karate";

    this->Create(nome1);
    this->Create(nome3);
    this->Create(nome2);
    this->Create(nome4);
}

Modalidade **ModalidadeDAO::GetModalidades()
{
    return this->modalidades;
}

Modalidade* ModalidadeDAO::Create(char* nome){
    /* Adicionar modalidade ao vetor de modalidades */

    Modalidade *modalidade = new Modalidade;
    modalidade->SetNome(nome);
    this->modalidades[this->quantidadeModalidade++] = modalidade;
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

