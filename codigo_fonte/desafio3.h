#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../bibioteca/json.hpp"

class Desafio3
{

public:
    Desafio3()
    {
        std::cout << "DESAFIO 3:\n";
        std::cout << "=================\n";
        std::string json_str = lerJsonFile("faturamento_mensal.json");
        std::vector<double> vec = addJsonNoVetor(json_str);
        removerZeros(vec);
        for(double i : vec)
        {
            std::cout << i << "\n";
        }
        exibirMenorFaturamento(vec);
        exibirMaiorFaturamento(vec);        
    };

private:  

    std::string lerJsonFile(std::string nome_arquivo)
    {
        std::ifstream file(nome_arquivo);
        if(!file.is_open())
        {
            throw std::runtime_error("Não foi possivel ler o arquivo.\n");
        }
        std::string conteudo((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return conteudo;
    }

    std::vector<double> addJsonNoVetor(const std::string &jsonString) 
    {
        nlohmann::json dados_json = nlohmann::json::parse(jsonString);
        std::vector<double> faturamento_mensal;

        for (const auto& item : dados_json["faturamento"]) 
        {
        double valor = item["valor"].get<double>();
        faturamento_mensal.push_back(valor);
        }

        return faturamento_mensal;
    }

    //Criei essa função para remover os valores nulos do final de semana (R$ 0), para que não interfiram no calculo da media e na exibicao de menor faturamento do mes
    void removerZeros(std::vector<double> &faturamento)
    {
        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if(faturamento[i] == 0.0)
            {
                faturamento.erase(faturamento.begin() + i);
                i = i - 1;
            }
        }
    }

    void exibirMenorFaturamento(std::vector<double> &faturamento)
    {
        double menor_valor;
        
        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if((faturamento[i] !=0) && (faturamento[i] < menor_valor))
            {
                menor_valor = faturamento[i];
            }
        }

        std::cout << "O menor valor de faturamento ocorrido em um dia do mes foi " << menor_valor << "\n";
    }

    void exibirMaiorFaturamento(std::vector<double> &faturamento)
    {
        double maior_valor = faturamento[0];
        
        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if(faturamento[i] > maior_valor)
            {
                maior_valor = faturamento[i];
            }
        }

        std::cout << "O maior valor de faturamento ocorrido em um dia do mes foi " << maior_valor << "\n";
    }     
};


