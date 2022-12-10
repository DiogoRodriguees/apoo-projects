#include "ProfessorDAO.hpp"

Professor* ProfessorDAO::Retrive(int cpf){
    Professor *professor = new Professor; // pensar em uma maneira de armaenar ovarios professores
    char nome[25] = "Lucio Valentin";
    professor->SetNome(nome);
    professor->SetSalario(15000);
    professor->SetInativo(false);
    professor->SetCPF(123);
    

    return professor;
}