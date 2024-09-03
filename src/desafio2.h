#pragma once
#include <iostream>
#include <vector>
#include <string>

class Desafio2
{
public: 
    Desafio2()
    {
        std::cout << "==================================\n";
        std::cout << "DESAFIO 2:\n\n";
        processar();
        std::cout << "==================================\n";
    }

private:
    int numero{0};
    bool entradaValida{false};
    std::vector<int> fibonacci{0,1};

    void validarEntradaNumerica(const std::string& input)
    {
        try
        {
            numero = std::stoi(input);
            entradaValida = true;
        }
        catch(const std::invalid_argument&)
        {
            entradaValida = false;
            std::cout << "Entrada invalida. Por favor, insira um numero valido.\n";
        }
    }

    void checarFibonacci(int numero)
    {
        while(fibonacci.back() < numero)
        {
            fibonacci.push_back(fibonacci[fibonacci.size() - 2] + fibonacci.back());
        }

        bool pertence = false;
        for(const int& num : fibonacci)
        {
            if(num == numero)
            {
                pertence = true;
                break;
            }
        }

        if(pertence)
        {
            std::cout << "O numero " << numero << " pertence a sequencia de Fibonacci.\n";
        }
        else
        {
            std::cout << "O numero " << numero << " nao pertence a sequencia de Fibonacci.\n";
        }
    }

    void processar()
    {
        std::string input;

        do
        {
            std::cout << "Informe um numero: \n";
            std::cin >> input;
            validarEntradaNumerica(input);

        } while (!entradaValida);

        checarFibonacci(numero);
    }
};