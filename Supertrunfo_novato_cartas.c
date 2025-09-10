#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char codigo[4];           // Código da carta (ex: "A01")
    char estado[50];          // Nome do estado
    char cidade[50];          // Nome da cidade
    int populacao;            // População
    float area;               // Área em km²
    float pib;                // PIB em reais
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_pop;      // Densidade populacional (calculada)
    float pib_per_capita;     // PIB per capita (calculado)
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== CADASTRO DA CARTA %d ===\n", numero);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome do estado: ");
    scanf("%s", carta->estado);
    
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->cidade);
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (em reais): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcular valores derivados
    carta->densidade_pop = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir informações de uma carta
void exibirCarta(Carta carta) {
    printf("\n--- Informações da Carta %s ---\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_pop);
    printf("PIB per capita: R$ %.2f\n", carta.pib_per_capita);
}

// Função para comparar cartas por população
void compararPorPopulacao(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR POPULAÇÃO ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.cidade, carta2.estado, carta2.populacao);
    
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar cartas por área
void compararPorArea(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR ÁREA ===\n");
    printf("Carta 1 - %s (%s): %.2f km²\n", carta1.cidade, carta1.estado, carta1.area);
    printf("Carta 2 - %s (%s): %.2f km²\n", carta2.cidade, carta2.estado, carta2.area);
    
    if (carta1.area > carta2.area) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.area > carta1.area) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar cartas por PIB
void compararPorPIB(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR PIB ===\n");
    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.cidade, carta1.estado, carta1.pib);
    printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.cidade, carta2.estado, carta2.pib);
    
    if (carta1.pib > carta2.pib) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pib > carta1.pib) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar cartas por pontos turísticos
void compararPorPontosTuristicos(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR PONTOS TURÍSTICOS ===\n");
    printf("Carta 1 - %s (%s): %d pontos\n", carta1.cidade, carta1.estado, carta1.pontos_turisticos);
    printf("Carta 2 - %s (%s): %d pontos\n", carta2.cidade, carta2.estado, carta2.pontos_turisticos);
    
    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar cartas por densidade populacional
// ATENÇÃO: Para densidade populacional, o MENOR valor vence!
void compararPorDensidadePopulacional(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR DENSIDADE POPULACIONAL ===\n");
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.cidade, carta1.estado, carta1.densidade_pop);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.cidade, carta2.estado, carta2.densidade_pop);
    
    // Para densidade populacional, o MENOR valor vence
    if (carta1.densidade_pop < carta2.densidade_pop) {
        printf("Resultado: Carta 1 (%s) venceu! (menor densidade populacional)\n", carta1.cidade);
    } else if (carta2.densidade_pop < carta1.densidade_pop) {
        printf("Resultado: Carta 2 (%s) venceu! (menor densidade populacional)\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar cartas por PIB per capita
void compararPorPIBPerCapita(Carta carta1, Carta carta2) {
    printf("\n=== COMPARAÇÃO POR PIB PER CAPITA ===\n");
    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
    
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;
    
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE CARTAS ===\n\n");
    
    // Cadastrar as duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibir informações das cartas cadastradas
    printf("\n=== CARTAS CADASTRADAS ===");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Menu para escolha do atributo de comparação
    printf("\n=== ESCOLHA O ATRIBUTO PARA COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    
    // Realizar a comparação baseada na escolha
    switch(opcao) {
        case 1:
            compararPorPopulacao(carta1, carta2);
            break;
        case 2:
            compararPorArea(carta1, carta2);
            break;
        case 3:
            compararPorPIB(carta1, carta2);
            break;
        case 4:
            compararPorPontosTuristicos(carta1, carta2);
            break;
        case 5:
            compararPorDensidadePopulacional(carta1, carta2);
            break;
        case 6:
            compararPorPIBPerCapita(carta1, carta2);
            break;
        default:
            printf("Opção inválida! Comparando por população por padrão.\n");
            compararPorPopulacao(carta1, carta2);
            break;
    }
    
    printf("\n=== FIM DO JOGO ===\n");
    printf("Obrigado por jogar Super Trunfo!\n");
    
    return 0;
}