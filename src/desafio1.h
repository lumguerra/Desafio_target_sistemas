#pragma once
#include <iostream>

class Desafio1
{
public:
    Desafio1()
    {
        std::cout << "==================================\n";
        std::cout << "DESAFIO 1:\n\n";
        calcularSoma();
        std::cout << "==================================\n";
    }

private:
    int const INDICE{13};
    int SOMA{0};
    int K{0};

    void calcularSoma()
    {
        while(K < INDICE)
        {
            K += 1;
            SOMA = SOMA + K;
        }
        std::cout << "SOMA = " << SOMA << "\n";
    }
};