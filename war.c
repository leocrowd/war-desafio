#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constantes para configuração do jogo
#define NUM_TERRITORIOS 5
#define MAX_NOME 50
#define TROPAS_INICIAIS 10
#define COR_JOGADOR "Azul" // A cor do jogador principal


// Estrutura para armazenar os dados de cada território.
typedef struct {
    char nome[MAX_NOME];
    char corExercito[MAX_NOME];
    int numeroTropas;
} Territorio;

// Protótipos das funções para organizar o código.
void inicializarTerritorios(Territorio *mapa, int tam);
void exibirMapa(const Territorio *mapa, int tam);
void faseDeAtaque(Territorio *mapa, int tam);
void atribuirMissao(int *missaoAtual);
void verificarMissao(const Territorio *mapa, int tam, int missaoAtual);
int lancarDado();

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Substitui o vetor estático por memória alocada dinamicamente.
    Territorio *mapa = (Territorio *)calloc(NUM_TERRITORIOS, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria para o mapa!\n");
        return 1;
    }

    int opcao;
    int missaoAtual;

    // --- Funções e Sistema de Missões ---
    inicializarTerritorios(mapa, NUM_TERRITORIOS);
    atribuirMissao(&missaoAtual);

    printf("Bem-vindo ao Desafio WAR Estruturado!\n");
    printf("Sua cor e %s.\n", COR_JOGADOR);

    // --- Menu Interativo ---
    do {
        exibirMapa(mapa, NUM_TERRITORIOS);

        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Atacar\n");
        printf("2. Verificar Missao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                faseDeAtaque(mapa, NUM_TERRITORIOS);
                break;
            case 2:
                verificarMissao(mapa, NUM_TERRITORIOS, missaoAtual);
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // --- Liberação de memória com free() ---
    free(mapa);
    mapa = NULL;

    return 0;
}

// --- Inicialização automatica ---
void inicializarTerritorios(Territorio *mapa, int tam) {
    // Território 1 (Jogador)
    strcpy(mapa[0].nome, "Brasil");
    strcpy(mapa[0].corExercito, COR_JOGADOR);
    mapa[0].numeroTropas = TROPAS_INICIAIS;

    // Território 2 (Inimigo Verde)
    strcpy(mapa[1].nome, "Argentina");
    strcpy(mapa[1].corExercito, "Verde");
    mapa[1].numeroTropas = TROPAS_INICIAIS;

    // Outros territórios
    strcpy(mapa[2].nome, "Peru");
    strcpy(mapa[2].corExercito, "Vermelho");
    mapa[2].numeroTropas = 5;

    strcpy(mapa[3].nome, "Venezuela");
    strcpy(mapa[3].corExercito, "Amarelo");
    mapa[3].numeroTropas = 5;
    
    strcpy(mapa[4].nome, "Chile");
    strcpy(mapa[4].corExercito, "Verde");
    mapa[4].numeroTropas = 3;
}

// --- Exibição do Mapa ---
void exibirMapa(const Territorio *mapa, int tam) {
    printf("\n--- ESTADO ATUAL DO MAPA ---\n");
    for (int i = 0; i < tam; i++) {
        printf("%d: %-15s | Cor: %-10s | Tropas: %d\n",
               i + 1,
               mapa[i].nome,
               mapa[i].corExercito,
               mapa[i].numeroTropas);
    }
}

// --- Função para lançar o dado ---
int lancarDado() {
    // --- Aleatoriedade com rand() ---
    return (rand() % 6) + 1;
}

// --- Fase de Ataque ---
void faseDeAtaque(Territorio *mapa, int tam) {
    int idAtacante, idDefensor;

    printf("\n--- FASE DE ATAQUE ---\n");
    printf("Escolha o territorio atacante (1 a %d): ", tam);
    scanf("%d", &idAtacante);
    printf("Escolha o territorio defensor (1 a %d): ", tam);
    scanf("%d", &idDefensor);

    // Converte para índice do vetor (0 a tam-1)
    idAtacante--;
    idDefensor--;

    // Validações básicas
    if (idAtacante < 0 || idAtacante >= tam || idDefensor < 0 || idDefensor >= tam) {
        printf("IDs invalidos!\n");
        return;
    }
    if (idAtacante == idDefensor) {
        printf("Um territorio nao pode atacar a si mesmo!\n");
        return;
    }
    if (mapa[idAtacante].numeroTropas <= 1) {
        printf("O territorio atacante precisa ter mais de 1 tropa para atacar!\n");
        return;
    }
    if (strcmp(mapa[idAtacante].corExercito, mapa[idDefensor].corExercito) == 0) {
        printf("Voce nao pode atacar um territorio que ja e seu!\n");
        return;
    }

    // Lógica da batalha
    int dadoAtaque = lancarDado();
    int dadoDefesa = lancarDado();

    printf("\nBatalha: %s (%d) ataca %s (%d)\n", mapa[idAtacante].nome, dadoAtaque, mapa[idDefensor].nome, dadoDefesa);

    // --- Lógica da Batalha ---
    // Empate favorece o atacante
    if (dadoAtaque >= dadoDefesa) {
        printf("VITORIA DO ATACANTE! O defensor perdeu 1 tropa.\n");
        mapa[idDefensor].numeroTropas--;

        if (mapa[idDefensor].numeroTropas == 0) {
            printf("TERRITORIO CONQUISTADO! %s agora pertence ao exercito %s.\n",
                   mapa[idDefensor].nome, mapa[idAtacante].corExercito);
            
            // Conquista o território
            strcpy(mapa[idDefensor].corExercito, mapa[idAtacante].corExercito);
            mapa[idDefensor].numeroTropas = 1; // Território conquistado fica com 1 tropa
            mapa[idAtacante].numeroTropas--;   // A tropa que se move para o novo território
        }
    } else {
        printf("VITORIA DO DEFENSOR! O ataque falhou.\n");
    }
}

// --- Sistema de Missões ---
void atribuirMissao(int *missaoAtual) {
    *missaoAtual = rand() % 2; // Sorteia 0 ou 1
    printf("\n--- SUA MISSAO FOI DEFINIDA ---\n");
    if (*missaoAtual == 0) {
        printf("Missao: Destruir o exercito VERDE.\n");
    } else {
        printf("Missao: Conquistar 3 territorios.\n");
    }
}

// --- Verificação de Missões ---
void verificarMissao(const Territorio *mapa, int tam, int missaoAtual) {
    int condicaoCumprida = 1; // Começa como verdadeiro

    printf("\n--- VERIFICANDO MISSAO ---\n");

    if (missaoAtual == 0) { // Missão: Destruir o exército Verde
        condicaoCumprida = 1;
        for (int i = 0; i < tam; i++) {
            if (strcmp(mapa[i].corExercito, "Verde") == 0) {
                condicaoCumprida = 0; // Encontrou um território verde, missão não cumprida
                break;
            }
        }
        if (condicaoCumprida) {
            printf("MISSAO CUMPRIDA! Voce destruiu o exercito Verde!\n");
        } else {
            printf("Missao em andamento: Ainda existem territorios do exercito Verde.\n");
        }

    } else if (missaoAtual == 1) { // Missão: Conquistar 3 territórios
        int contagem = 0;
        for (int i = 0; i < tam; i++) {
            if (strcmp(mapa[i].corExercito, COR_JOGADOR) == 0) {
                contagem++;
            }
        }
        if (contagem >= 3) {
            printf("MISSAO CUMPRIDA! Voce conquistou %d territorios!\n", contagem);
        } else {
            printf("Missao em andamento: Voce possui %d de 3 territorios necessarios.\n", contagem);
        }
    }
}