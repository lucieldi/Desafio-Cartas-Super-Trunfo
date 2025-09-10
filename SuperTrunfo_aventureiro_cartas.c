#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler string com espaços
void lerString(char *str, int tamanho, const char *prompt) {
    printf("%s", prompt);
    fgets(str, tamanho, stdin);
    // Remove o \n do final da string
    str[strcspn(str, "\n")] = 0;
}

// Função para validar entrada numérica
int lerInteiro(const char *prompt) {
    int valor;
    printf("%s", prompt);
    while (scanf("%d", &valor) != 1 || valor < 0) {
        printf("Erro: Digite um número válido (não negativo): ");
        limparBuffer();
    }
    limparBuffer();
    return valor;
}

// Função para validar entrada float
float lerFloat(const char *prompt) {
    float valor;
    printf("%s", prompt);
    while (scanf("%f", &valor) != 1 || valor < 0) {
        printf("Erro: Digite um número válido (não negativo): ");
        limparBuffer();
    }
    limparBuffer();
    return valor;
}

// Função para cadastrar uma carta com validação
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== CADASTRO DA CARTA %d ===\n", numero);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    limparBuffer();
    
    lerString(carta->estado, sizeof(carta->estado), "Digite o nome do estado: ");
    lerString(carta->cidade, sizeof(carta->cidade), "Digite o nome da cidade: ");
    
    carta->populacao = lerInteiro("Digite a população: ");
    carta->area = lerFloat("Digite a área (km²): ");
    carta->pib = lerFloat("Digite o PIB (em reais): ");
    carta->pontos_turisticos = lerInteiro("Digite o número de pontos turísticos: ");
    
    // Calcular valores derivados com validação
    if (carta->area > 0) {
        carta->densidade_pop = carta->populacao / carta->area;
    } else {
        carta->densidade_pop = 0;
        printf("Aviso: Área zero, densidade populacional definida como 0.\n");
    }
    
    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
        printf("Aviso: População zero, PIB per capita definido como 0.\n");
    }
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

// Função genérica para comparar cartas
void compararCartas(Carta carta1, Carta carta2, int opcao) {
    const char* nomes_atributos[] = {
        "", "POPULAÇÃO", "ÁREA", "PIB", "PONTOS TURÍSTICOS", 
        "DENSIDADE POPULACIONAL", "PIB PER CAPITA"
    };
    
    printf("\n=== COMPARAÇÃO POR %s ===\n", nomes_atributos[opcao]);
    
    int resultado = 0; // 0 = empate, 1 = carta1 vence, 2 = carta2 vence
    
    switch(opcao) {
        case 1: // População
            printf("Carta 1 - %s (%s): %d habitantes\n", 
                   carta1.cidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d habitantes\n", 
                   carta2.cidade, carta2.estado, carta2.populacao);
            
            if (carta1.populacao > carta2.populacao) {
                resultado = 1;
            } else if (carta2.populacao > carta1.populacao) {
                resultado = 2;
            }
            break;
            
        case 2: // Área
            printf("Carta 1 - %s (%s): %.2f km²\n", 
                   carta1.cidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km²\n", 
                   carta2.cidade, carta2.estado, carta2.area);
            
            if (carta1.area > carta2.area) {
                resultado = 1;
            } else if (carta2.area > carta1.area) {
                resultado = 2;
            }
            break;
            
        case 3: // PIB
            printf("Carta 1 - %s (%s): R$ %.2f\n", 
                   carta1.cidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): R$ %.2f\n", 
                   carta2.cidade, carta2.estado, carta2.pib);
            
            if (carta1.pib > carta2.pib) {
                resultado = 1;
            } else if (carta2.pib > carta1.pib) {
                resultado = 2;
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Carta 1 - %s (%s): %d pontos\n", 
                   carta1.cidade, carta1.estado, carta1.pontos_turisticos);
            printf("Carta 2 - %s (%s): %d pontos\n", 
                   carta2.cidade, carta2.estado, carta2.pontos_turisticos);
            
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                resultado = 1;
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                resultado = 2;
            }
            break;
            
        case 5: // Densidade Populacional (MENOR VENCE!)
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", 
                   carta1.cidade, carta1.estado, carta1.densidade_pop);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n", 
                   carta2.cidade, carta2.estado, carta2.densidade_pop);
            
            // Para densidade populacional, o MENOR valor vence
            if (carta1.densidade_pop < carta2.densidade_pop) {
                resultado = 1;
            } else if (carta2.densidade_pop < carta1.densidade_pop) {
                resultado = 2;
            }
            break;
            
        case 6: // PIB per capita
            printf("Carta 1 - %s (%s): R$ %.2f\n", 
                   carta1.cidade, carta1.estado, carta1.pib_per_capita);
            printf("Carta 2 - %s (%s): R$ %.2f\n", 
                   carta2.cidade, carta2.estado, carta2.pib_per_capita);
            
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                resultado = 1;
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                resultado = 2;
            }
            break;
    }
    
    // Exibir resultado
    printf("\n");
    if (resultado == 1) {
        printf("🏆 Resultado: Carta 1 (%s) VENCEU!", carta1.cidade);
        if (opcao == 5) {
            printf(" (menor densidade populacional)");
        }
        printf("\n");
    } else if (resultado == 2) {
        printf("🏆 Resultado: Carta 2 (%s) VENCEU!", carta2.cidade);
        if (opcao == 5) {
            printf(" (menor densidade populacional)");
        }
        printf("\n");
    } else {
        printf("🤝 Resultado: EMPATE!\n");
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n=== ESCOLHA O ATRIBUTO PARA COMPARAÇÃO ===\n");
    printf("1 - População (maior vence)\n");
    printf("2 - Área (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos Turísticos (maior vence)\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per capita (maior vence)\n");
    printf("0 - Sair do jogo\n");
    printf("Digite sua opção: ");
}

// Função para validar opção do menu
int lerOpcaoMenu() {
    int opcao;
    while (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 6) {
        printf("Opção inválida! Digite um número entre 0 e 6: ");
        limparBuffer();
    }
    limparBuffer();
    return opcao;
}

int main() {
    Carta carta1, carta2;
    int opcao;
    char jogar_novamente;
    
    printf("🃏 === SUPER TRUNFO - COMPARAÇÃO DE CARTAS === 🃏\n");
    printf("Bem-vindo ao jogo de cartas dos estados brasileiros!\n\n");
    
    // Cadastrar as duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Loop principal do jogo
    do {
        // Exibir informações das cartas cadastradas
        printf("\n=== CARTAS CADASTRADAS ===");
        exibirCarta(carta1);
        exibirCarta(carta2);
        
        // Menu para escolha do atributo de comparação
        exibirMenu();
        opcao = lerOpcaoMenu();
        
        if (opcao == 0) {
            printf("\nObrigado por jogar Super Trunfo! 👋\n");
            break;
        }
        
        // Realizar a comparação
        compararCartas(carta1, carta2, opcao);
        
        // Perguntar se quer jogar novamente
        printf("\nDeseja fazer uma nova comparação? (s/n): ");
        scanf(" %c", &jogar_novamente);
        limparBuffer();
        
    } while (tolower(jogar_novamente) == 's');
    
    printf("\n=== FIM DO JOGO ===\n");
    printf("🎮 Obrigado por jogar Super Trunfo! 🎮\n");
    
    return 0;
}