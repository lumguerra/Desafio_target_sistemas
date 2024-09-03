
# Projeto de Desafios para o processo seletivo da Target Sistemas

Este repositório contém uma série de desafios escritos em C++, que fazem parte do processo seletivo da empresa Target Sistemas. Esses desafios abordam diversos conceitos, como manipulação de strings, cálculos matemáticos, uso de estruturas de dados e leitura de arquivos JSON. Eles foram implementados para praticar e demonstrar minhas habilidades em programação e processamento de dados.

## Estrutura do Projeto

```
├── src/
│   ├── Desafio1.hpp
│   ├── Desafio2.hpp
│   ├── Desafio3.hpp
│   ├── Desafio4.hpp
│   ├── Desafio5.hpp
│   └── main.cpp
├── libs/
│   └── json.hpp
├── data/
│   └── faturamento_mensal.json
├── README.md
```

### Descrição das Pastas

- **src/**: Contém os arquivos de código-fonte do projeto, onde cada desafio está implementado em um arquivo `.hpp`.
- **libs/**: Armazena a biblioteca externa `nlohmann/json` usada para manipulação de arquivos JSON.
- **data/**: Contém o arquivo `faturamento_mensal.json` usado pelo Desafio 3.
- **README.md**: Este arquivo que você está lendo, com instruções e informações sobre o projeto.

## Como Compilar e Executar

### Requisitos

- **C++17** ou superior
- Um compilador C++ como `g++` ou `clang++`

### Passos para Compilação

1. **Clone o repositório:**

   ```sh
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   cd nome-do-repositorio
   ```

2. **Compile o projeto:**

   ```sh
   g++ .\main.cpp
   ```

   Isso compilará todos o arquivo `.cpp` no diretório `src/` e criará o executável resultante dentro da mesma pasta.

3. **Execute o programa:**

   ```sh
   .\a.exe   
   ```

   O programa será executado, apresentando os resultados dos desafios implementados.

## Descrição dos Desafios

### Desafio 1: Cálculo de Soma Sequencial
Este desafio calcula a soma de uma sequência de números de 1 até um valor limite predefinido (13).

### Desafio 2: Verificação na Sequência de Fibonacci
O desafio verifica se um número fornecido pelo usuário pertence à sequência de Fibonacci.

### Desafio 3: Análise de Faturamento Mensal
Este desafio processa um arquivo JSON contendo o faturamento diário de uma empresa e realiza cálculos como menor e maior faturamento, e quantos dias tiveram faturamento acima da média.

### Desafio 4: Cálculo de Percentuais de Faturamento por Estado
O desafio calcula e exibe o percentual de representação do faturamento de diferentes estados em relação ao faturamento total.

### Desafio 5: Inversão de String
Este desafio inverte uma string predefinida e exibe o resultado.

## Autor

- **Lucas Mazoni Guerra** - [LinkedIn](https://www.linkedin.com/in/lucas-guerra-66a40a238/) | [Meu website](https://guerradev.com/)
