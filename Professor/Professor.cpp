#include "Professor.hpp"


Professor::Professor(){
    // Professor *professor = new Professor;
    // strcpy(professor->nome, "Lucio Valentin");
    // professor->salario = 15000;
    // professor->inativo = false;
    // professor->cpf = 12345678910;
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