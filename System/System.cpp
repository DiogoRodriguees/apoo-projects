#include "System.hpp"
#include "../ContratoCtrl/ContratoCtrl.hpp"
#include <iostream>

void System::BootSystem()
{
    bool systemLoad = true;

    while (systemLoad)
    {
        system("cls");
        std::cout << "\n\nBem Vindo\n";
        std::cout << "O que voce deseja?\n";
        std::cout << "1. Matricular Aluno\n";
        std::cout << "2. Criar Turma\n";
        std::cout << "3. Contratar Funcionario\n";
        std::cout << "0. Sair\n";

        char opcao;
        std::cin >> opcao;
        switch (opcao)
        {
            case '1':
            break;
            case '2':
            break;
            case '3':
                system("cls");
                this->IniciarContratoCtrl();
                this->ConfirmarContratoCtrl();
            break;
        case '0':
            systemLoad = false;
        }
    }
}

void System::IniciarContratoCtrl()
{
    ContratoCtrl contratoCtrl;

    int cpf;
    std::cout << "Informe o CPF do Professor a ser contratado\n";
    std::cin >> cpf;
    contratoCtrl.IniciarContrato(cpf);

    int inicio, fim;
    std::cout << "Informe a data de inicio:\n";
    std::cin >> inicio;
    std::cout << "Informe a  data de Termino:\n";
    std::cin >> fim;

    contratoCtrl.DefinirPeriodoDoContrato(inicio, fim);
}

void System::ConfirmarContratoCtrl()
{
    std::cout << "\n\nNome: Lucio\n";
    std::cout << "CPF: 123\n";
    std::cout << "Formacoes: Boxe, Judo.\n";
    std::cout << "Data de inicio do contrato: 23/08/2022\n";
    std::cout << "Data de Termino do contrato: 23/09/2022\n\n";

    char finalizar;
    std::cout << "Deseja confirmar as informacoes do contrato? (s)sim (n)nao\n";
    std::cin >> finalizar;
    system("cls");
    std::cout << "Contrato Finalizado com suceso";
}