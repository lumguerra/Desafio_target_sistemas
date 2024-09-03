#include "desafio1.h"
#include "desafio2.h"
#include "desafio3.h"
#include "desafio4.h"
#include "desafio5.h"

int main()
{
    bool continuar = true;
    int escolha;

    while (continuar)
    {
        std::cout << "\nEscolha o desafio que deseja executar:\n";
        std::cout << "1 - Desafio 1\n";
        std::cout << "2 - Desafio 2\n";
        std::cout << "3 - Desafio 3\n";
        std::cout << "4 - Desafio 4\n";
        std::cout << "5 - Desafio 5\n";
        std::cout << "0 - Sair\n";
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        switch (escolha)
        {
            case 1:
                {
                    Desafio1 d1;
                    break;
                }
            case 2:
                {
                    Desafio2 d2;
                    break;
                }
            case 3:
                {
                    Desafio3 d3;
                    break;
                }
            case 4:
                {
                    Desafio4 d4;
                    break;
                }
            case 5:
                {
                    Desafio5 d5;
                    break;
                }
            case 0:
                {
                    continuar = false;
                    std::cout << "==================================\n";
                    std::cout << "Saindo do programa...\n";
                    std::cout << "==================================\n";
                    break;
                }
            default:
                {
                    std::cout << "Escolha não identificada. Por favor, digite o número relativo à sua escolha.\n";
                    break;
                }
        }
    }

    return 0;
}
