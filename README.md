# 🗺️ Projeto de Estrutura de Dados: Desafio WAR em C

**Projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados do curso de Análise e Desenvolvimento de Sistemas (ADS) da Universidade Estácio de Sá.**

Este projeto consiste na implementação de uma versão estruturada do clássico jogo de tabuleiro WAR, utilizando a linguagem C. O objetivo é aplicar conceitos fundamentais de programação e estrutura de dados de forma progressiva e modular.

---

## 🎯 Sobre o Projeto

A proposta do desafio é criar uma simulação do jogo WAR, focando na conquista de territórios. O desenvolvimento foi dividido em três níveis de complexidade crescente, permitindo a aplicação gradual de diferentes conceitos da linguagem C:

1.  **Nível Novato:** Focado na criação da estrutura de dados principal (`struct`) e no manuseio de vetores estáticos para cadastrar e exibir os territórios.
2.  **Nível Aventureiro:** Introduziu o uso de **ponteiros** e **alocação dinâmica de memória** (`calloc`/`free`), além da lógica para simular batalhas com números aleatórios (`rand`).
3.  **Nível Mestre:** Consolidou o aprendizado com a **modularização total** do código em funções, a implementação de um sistema de missões e a aplicação de boas práticas de programação, como o uso de `const`.

A versão final presente neste repositório corresponde à implementação do **Nível Mestre**, que engloba todas as funcionalidades e conceitos dos níveis anteriores.

---

## ⚙️ Funcionalidades Implementadas

* **Inicialização Automática:** O mapa do jogo é pré-carregado com 5 territórios, exércitos e tropas.
* **Menu Interativo:** O jogador pode escolher entre atacar, verificar o status da sua missão ou sair do jogo.
* **Simulação de Batalha:** Lógica de ataque e defesa baseada em "rolagem de dados" aleatórios.
* **Conquista de Territórios:** Se um exército defensor perde todas as suas tropas, o território é conquistado pelo atacante.
* **Sistema de Missões:** No início do jogo, uma de duas missões aleatórias é atribuída ao jogador:
    1.  Destruir completamente um exército de uma cor específica.
    2.  Conquistar um número mínimo de territórios.
* **Verificação de Missão:** O jogador pode, a qualquer momento, verificar se já cumpriu seu objetivo.
* **Gerenciamento de Memória:** O mapa do jogo é alocado dinamicamente, e a memória é liberada de forma segura ao final da execução.

---

## 💡 Conceitos de Estrutura de Dados e C Aplicados

Este projeto foi uma oportunidade para praticar e demonstrar conhecimento nos seguintes tópicos:

* **`struct`:** Para modelar entidades complexas (`Territorio`) agrupando diferentes tipos de dados.
* **Vetores:** Como estrutura de dados primária para armazenar o conjunto de territórios.
* **Ponteiros:** Para manipulação eficiente da memória e passagem de parâmetros por referência para as funções.
* **Alocação Dinâmica de Memória:** Uso de `calloc` para alocar o vetor de territórios em tempo de execução e `free` para evitar vazamento de memória.
* **Modularização:** Divisão do código em funções com responsabilidades únicas, melhorando a organização, legibilidade e manutenção.
* **Entrada e Saída (I/O):** Interação com o usuário via terminal usando `printf` e `scanf`.
* **Manipulação de Strings:** Uso de funções da biblioteca `<string.h>` como `strcpy` e `strcmp`.
* **Boas Práticas:** Uso de `const` em parâmetros de funções para garantir que os dados não sejam alterados indevidamente.

---

## 🚀 Como Executar o Projeto

Para compilar e executar este projeto, você
