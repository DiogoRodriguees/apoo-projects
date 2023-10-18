#pragma once
#include <string.h>
#include "../Modalidade/Modalidade.hpp"

class Professor{
    char nome[25];
    int cpf;
    float salario;
    bool inativo;
    Modalidade *modalidades[15];
    int nova;

public:
    Professor();

    void SetNome(char*);
    char* GetNome();

    void SetCPF(int);
    int GetCPF();

    void SetInativo(bool);
    char GetInativo();

    void SetSalario(float);
    float GetSalario();

    void SetModalidade(Modalidade*);

    Modalidade* GetModalidade();
    Modalidade** GetModalidades(); // reveer o tipo de retorno

    int GetQuantidadeModalidade();

};