#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 3 - Interatividade no Super Trunfo

struct Carta {
    char estado;
    char codigo[3];
    char cidade[50];
    unsigned long int populacao;
    float areaDaCidade;
    float pib;
    int qtdPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superpoder;
};

int main() {
    short int opcao;
    /*
        Cadastrando informações da Carta 1:
    */
    printf(" --- Criando cartas --- \n\n");
    struct Carta carta1;
    printf("| --- Carta 1 --- |");
    printf("\nInforme um estado ('A' a 'H'): ");
    scanf(" %c", &carta1.estado);
    getchar();
    printf("Informe um código ('01' a '04'): ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    getchar();
    printf("Informe o nome da cidade: ");
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = '\0'; // substituindo o caractere de nova linha ('\n') pelo terminador de string ('\0')
    printf("Informe a população: ");
    scanf("%ld", &carta1.populacao);
    printf("Informe a Área (km²): ");
    scanf("%f", &carta1.areaDaCidade);
    printf("Informe o PIB: ");
    scanf("%f", &carta1.pib);
    printf("Informe o número de Pontos Turísticos: ");
    scanf("%d", &carta1.qtdPontosTuristicos);
    
    // Impedindo o erro de divisão por 0
    carta1.populacao = carta1.populacao <= 0? 1 : carta1.populacao;
    carta1.areaDaCidade = carta1.areaDaCidade <= 0? 0.1 : carta1.areaDaCidade;

    carta1.densidadePopulacional = carta1.populacao / carta1.areaDaCidade;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta1.superpoder = carta1.populacao + carta1.areaDaCidade + carta1.pib + carta1.qtdPontosTuristicos + carta1.pibPerCapita + (1 / carta1.densidadePopulacional);
    printf("| --------------- |");

    printf("\n\n\n");
    /*
        Cadastrando informações da Carta 2:
    */
    struct Carta carta2;
    printf("| --- Carta 2 --- |");
    printf("\nInforme um estado ('A' a 'H'): ");
    scanf(" %c", &carta2.estado);
    getchar();
    printf("Informe um código ('01' a '04'): ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    getchar();
    printf("Informe o nome da cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0'; // substituindo o caractere de nova linha ('\n') pelo terminador de string ('\0')
    printf("Informe a população: ");
    scanf("%ld", &carta2.populacao);
    printf("Informe a Área (km²): ");
    scanf("%f", &carta2.areaDaCidade);
    printf("Informe o PIB: ");
    scanf("%f", &carta2.pib);
    printf("Informe o número de Pontos Turísticos: ");
    scanf("%d", &carta2.qtdPontosTuristicos);

    // Impedindo o erro de divisão por 0
    carta2.populacao = carta2.populacao <= 0? 1 : carta2.populacao;
    carta2.areaDaCidade = carta2.areaDaCidade <= 0? 0.1 : carta2.areaDaCidade;

    carta2.densidadePopulacional = carta2.populacao / carta2.areaDaCidade;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;
    carta2.superpoder = carta2.populacao + carta2.areaDaCidade + carta2.pib + carta2.qtdPontosTuristicos + carta2.pibPerCapita + (1 / carta2.densidadePopulacional);
    printf("| --------------- |");

    printf("\n\n\n\n\n");


    /*
        Comparando as cartas
    */
    // Menu interativo
    printf("| -------------- Menu -------------- |\n");
    printf("| Comparar:                          |\n");
    printf("|  -> 1. População                   |\n");
    printf("|  -> 2. Área                        |\n");
    printf("|  -> 3. PIB                         |\n");
    printf("|  -> 4. Número de Pontos Turísticos |\n");
    printf("|  -> 5. Densidade Demográfica       |\n");
    printf("| ---------------------------------- |\n");
    printf("->: ");
    scanf("%d", &opcao);

    printf("\n\n");
    
    switch (opcao) {
        case 1:
            printf("Cartas escolhidas: %s | %s\n", carta1.cidade, carta2.cidade);
            printf("Atributo escolhido: População\n");
            printf("Valor do atributo: \n");
            printf("  -> Carta %s: %ld\n", carta1.cidade, carta1.populacao);
            printf("  -> Carta %s: %ld\n", carta2.cidade, carta2.populacao);
            printf("Resultado: ");
            if(carta1.populacao > carta2.populacao)
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(carta1.populacao < carta2.populacao)
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");

            break;

        case 2:
            printf("Cartas escolhidas: %s | %s\n", carta1.cidade, carta2.cidade);
            printf("Atributo escolhido: Área\n");
            printf("Valor do atributo: \n");
            printf("  -> Carta %s: %.2f\n", carta1.cidade, carta1.areaDaCidade);
            printf("  -> Carta %s: %.2f\n", carta2.cidade, carta2.areaDaCidade);
            printf("Resultado: ");
            if(carta1.areaDaCidade > carta2.areaDaCidade)
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(carta1.areaDaCidade < carta2.areaDaCidade)
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");

            break;

        case 3:
            printf("Cartas escolhidas: %s | %s\n", carta1.cidade, carta2.cidade);
            printf("Atributo escolhido: PIB\n");
            printf("Valor do atributo: \n");
            printf("  -> Carta %s: %.2f\n", carta1.cidade, carta1.pib);
            printf("  -> Carta %s: %.2f\n", carta2.cidade, carta2.pib);
            printf("Resultado: ");
            if(carta1.pib > carta2.pib)
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(carta1.pib < carta2.pib)
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");

            break;

        case 4:
            printf("Cartas escolhidas: %s | %s\n", carta1.cidade, carta2.cidade);
            printf("Atributo escolhido: Número de Pontos Turísticos\n");
            printf("Valor do atributo: \n");
            printf("  -> Carta %s: %d\n", carta1.cidade, carta1.qtdPontosTuristicos);
            printf("  -> Carta %s: %d\n", carta2.cidade, carta2.qtdPontosTuristicos);
            printf("Resultado: ");
            if(carta1.qtdPontosTuristicos > carta2.qtdPontosTuristicos)
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(carta1.qtdPontosTuristicos < carta2.qtdPontosTuristicos)
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");

            break;

        case 5:
            printf("Cartas escolhidas: %s | %s\n", carta1.cidade, carta2.cidade);
            printf("Atributo escolhido: Densidade Demográfica\n");
            printf("Valor do atributo: \n");
            printf("  -> Carta %s: %.2f\n", carta1.cidade, carta1.densidadePopulacional);
            printf("  -> Carta %s: %.2f\n", carta2.cidade, carta2.densidadePopulacional);
            printf("Resultado: ");
            if(carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(carta1.densidadePopulacional > carta2.densidadePopulacional)
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");

            break;

        default:
            printf("\nOpção inválida!\n");
            break;
    }

    return 0;
}
