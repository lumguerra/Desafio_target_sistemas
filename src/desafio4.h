#pragma once
#include <iostream>
#include <map>
#include <vector>

class Desafio4
{
public:
    Desafio4()
    {
        std::cout << "==================================\n";
        std::cout << "DESAFIO 4:\n\n";
        processar();
        std::cout << "==================================\n";
    };

private:
    std::map<std::string, double> criarFaturamento()
    {
        std::map<std::string, double> faturamento;

        faturamento["SP"] = 67836.43;
        faturamento["RJ"] = 36678.66;
        faturamento["MG"] = 29229.88;
        faturamento["ES"] = 27165.48;
        faturamento["Outros"] = 19849.53;

        return faturamento;
    }

    double calcularValorTotal(std::map<std::string, double> &faturamento)
    {
        double valor_total{0};

        for(const auto& valor : faturamento)
        {
            valor_total += valor.second;
        }

        return valor_total;
    }

    std::vector<double> calcularPercentual(std::map<std::string, double> const &faturamento, double const &valor_total)
    {
        std::vector<double> percentuaisFaturamento;

        for(const auto& valor : faturamento)
        {
            double percentual = (valor.second / valor_total) * 100;
            percentuaisFaturamento.push_back(percentual);
        }

        return percentuaisFaturamento;
    }

    void exibirPercentuais(std::map<std::string, double> const &faturamento, std::vector<double> &percentuaisFaturamento)
    {
        auto it_faturamento = faturamento.begin();
        
        std::cout << "Percentual de representacao que cada estado teve dentro do valor total mensal da distribuidora: \n";

        for(size_t i = 0; i < faturamento.size(); ++i)
        {
            std::cout << it_faturamento->first << " - " << percentuaisFaturamento[i] << "%\n";
            ++it_faturamento;
        }        
    }

    void processar()
    {
        std::map<std::string, double> faturamento = criarFaturamento();
        double valor_total = calcularValorTotal(faturamento);
        std::vector<double> percentuaisFaturamento = calcularPercentual(faturamento, valor_total);
        exibirPercentuais(faturamento, percentuaisFaturamento);
    }
};