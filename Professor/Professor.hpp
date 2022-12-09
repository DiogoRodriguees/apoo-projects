#pragma once

class Professor{
    char nome[25];
    int cpf;
    float salario;
    bool inativo;

public:
    void getProfessor();
    void SetNome(char);
    void SetInativo(bool);
    void SetCPF(int);
    void SetSalario(float);
    char* GetNome();
    char GetInativo();
    int GetCPF();
    float GetSalario();
};