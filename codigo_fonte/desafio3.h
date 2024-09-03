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
        std::cout << "DESAFIO 3:\n\n";
        processar();
        std::cout << "==================================\n";
    };

private: 

    std::string lerArquivoJson(std::string nome_arquivo)
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

    //menor valor de faturamento ocorrido em um dia do mês
    double MenorFaturamento(std::vector<double> &faturamento)
    {
        removerZeros(faturamento);
        
        double menor_valor =  faturamento[0];

        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if(faturamento[i] < menor_valor)
            {
                menor_valor = faturamento[i];
            }
        }

        std::cout << "O menor valor de faturamento ocorrido em um dia do mes foi " << menor_valor << "\n";

        return menor_valor;
    }

    //maior valor de faturamento ocorrido em um dia do mês
    double calcularMaiorFaturamento(std::vector<double> &faturamento)
    {
        double maior_valor = faturamento[0];

        removerZeros(faturamento);
        
        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if(faturamento[i] > maior_valor)
            {
                maior_valor = faturamento[i];
            }
        }

        std::cout << "O maior valor de faturamento ocorrido em um dia do mes foi " << maior_valor << "\n";

        return maior_valor;
    }   

    double calcularMedia(std::vector<double> &faturamento)
    {
        removerZeros(faturamento);
        int qtd_dias = faturamento.size();
        double valor_total{0};

        for(double valor : faturamento)
        {
            valor_total += valor;
        }

        return valor_total / qtd_dias;        
    }  

    //número de dias no mês em que o valor de faturamento diário foi superior à média mensal
    int diasAcimaDaMedia(std::vector<double> faturamento)
    {
        double media = calcularMedia(faturamento);
        int dias_acima_media{0};

        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            if(faturamento[i] > media)
            {
                ++ dias_acima_media;
            }
        }

        std::cout << "Numero de dias no mes em que o valor de faturamento diario foi superior a media mensal: " << dias_acima_media << "\n";

        return dias_acima_media;        
    }

    void processar()
    {
        std::string json_str = lerArquivoJson("faturamento_mensal.json");
        std::vector<double> faturamento = addJsonNoVetor(json_str);
        MenorFaturamento(faturamento);
        calcularMaiorFaturamento(faturamento); 
        diasAcimaDaMedia(faturamento);
    }
};


