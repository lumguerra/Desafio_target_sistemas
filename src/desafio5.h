#include <iostream>
#include <vector>

class Desafio5
{
public:
    Desafio5()
    {
        std::cout << "DESAFIO 5:\n\n";
        std::cout << inverterString(str) << "\n";
        std::cout << "==================================\n";
    }

private:

    std::string str{"): aserpme ad otnemicserc o arap riubirtnoc e e sametsiS tegraT ad emit od etrap rezaf arap otnorp uotsE"};

    std::string inverterString(std::string &str)
    {
        std::string str_invertida(str.size(), '\0');

        for (size_t i = 0; i < str.size(); ++i)
        {
            str_invertida[i] = str[str.size() - 1 - i];
        }

        return str_invertida;
    }
};