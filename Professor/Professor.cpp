#include "Professor.hpp"


Professor::Professor(){
    this->nova = 0;
}

char* Professor::GetNome(){
    return this->nome;
}
char Professor::GetInativo(){
    return this->inativo;
}
int Professor::GetCPF(){
    return this->cpf;
}
float Professor::GetSalario(){
    return this->salario;
}
void Professor::SetNome(char* nome_recebido){
    strcpy(this->nome, nome_recebido);
}

void Professor::SetCPF(int cpf_recebido){
    this->cpf = cpf_recebido;
}

void Professor::SetInativo(bool inativo_recebido){
    this->inativo = inativo_recebido;
}

void Professor::SetSalario(float  salario_recebido){
    this->salario = salario_recebido;
}

void Professor::SetModalidade(Modalidade*modalidade){
    this->modalidades[nova] = modalidade;
    this->nova++;
}

Modalidade* Professor::GetModalidade(){
    /* refazer função, foi feita apenas para retirar warning do terminaç */
    return this->modalidades[0];
}

Modalidade** Professor::GetModalidades(){
    return this->modalidades;
}

int Professor::GetQuantidadeModalidade(){
    return this->nova;
}