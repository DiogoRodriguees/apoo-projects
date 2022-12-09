#pragma once

class Professor{
    char nome[25];
    int cpf;
    float salario;
    bool inativo;

public:
    void SetNome(char);
    char* GetNome();

    void SetCPF(int);
    int GetCPF();

    void SetInativo(bool);
    char GetInativo();

    void SetSalario(float);
    float GetSalario();
};