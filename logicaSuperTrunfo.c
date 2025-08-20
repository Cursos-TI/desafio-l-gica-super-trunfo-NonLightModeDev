#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 3 - Interatividade no Super Trunfo

struct Carta {
    char estado;
    char codigo[3];
    char cidade[50];
    long int populacao;
    float areaDaCidade;
    float pib;
    int qtdPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superpoder;
};

int main() {
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
    int atributo1, atributo2;
    // Menu interativo
    printf("| -------------- Menu -------------- |\n");
    printf("| Comparar (escolha 2 atributos):    |\n");
    printf("|  -> 1. População                   |\n");
    printf("|  -> 2. Área                        |\n");
    printf("|  -> 3. PIB                         |\n");
    printf("|  -> 4. Número de Pontos Turísticos |\n");
    printf("|  -> 5. Densidade Demográfica       |\n");
    printf("| ---------------------------------- |\n");
    printf("->: ");
    scanf("%d", &atributo1);
    printf("->: ");
    scanf("%d", &atributo2);

    printf("\n\n");

    // Verificando se os atributos escolhidos são iguais
    if(atributo1 == atributo2) {
        printf("Você não pode escolher o mesmo atributo 2 vezes.");
        printf("\nFim!\n");
    } else if((atributo1 < 1 || atributo1 > 5) && (atributo2 < 1 || atributo2 > 5)) { // Verificando se as escolhas estão dentro dos limites
        printf("\nAtributo(s) inválido(s)\n");
        printf("\nFim!\n");
    } else {
        // Comparando as cartas
        float somaDosAtributosDaCarta1, somaDosAtributosDaCarta2;
        float valorDosAtributosDaCarta1[2], valorDosAtributosDaCarta2[2];
        char nomeAtributo1[50], nomeAtributo2[50];
        
        // Configurando nome dos atributos e seus valores
        switch(atributo1) {
            case 1:
                strcpy(nomeAtributo1, "População");
                valorDosAtributosDaCarta1[0] = carta1.populacao;
                valorDosAtributosDaCarta2[0] = carta2.populacao;
                break;

            case 2:
                strcpy(nomeAtributo1, "Área");
                valorDosAtributosDaCarta1[0] = carta1.areaDaCidade;
                valorDosAtributosDaCarta2[0] = carta2.areaDaCidade;
                break;
            case 3:
                strcpy(nomeAtributo1, "PIB");
                valorDosAtributosDaCarta1[0] = carta1.pib;
                valorDosAtributosDaCarta2[0] = carta2.pib;
                break;
            case 4:
                strcpy(nomeAtributo1, "Número de Pontos Turísticos");
                valorDosAtributosDaCarta1[0] = carta1.qtdPontosTuristicos;
                valorDosAtributosDaCarta2[0] = carta2.qtdPontosTuristicos;
                break;
            case 5:
                strcpy(nomeAtributo1, "Densidade Demográfica");
                valorDosAtributosDaCarta1[0] = carta1.densidadePopulacional;
                valorDosAtributosDaCarta2[0] = carta2.densidadePopulacional;
                break;
        }

        switch(atributo2) {
            case 1:
                strcpy(nomeAtributo2, "População");
                valorDosAtributosDaCarta1[1] = carta1.populacao;
                valorDosAtributosDaCarta2[1] = carta2.populacao;
                break;

            case 2:
                strcpy(nomeAtributo2, "Área");
                valorDosAtributosDaCarta1[1] = carta1.areaDaCidade;
                valorDosAtributosDaCarta2[1] = carta2.areaDaCidade;
                break;
            case 3:
                strcpy(nomeAtributo2, "PIB");
                valorDosAtributosDaCarta1[1] = carta1.pib;
                valorDosAtributosDaCarta2[1] = carta2.pib;
                break;
            case 4:
                strcpy(nomeAtributo2, "Número de Pontos Turísticos");
                valorDosAtributosDaCarta1[1] = carta1.qtdPontosTuristicos;
                valorDosAtributosDaCarta2[1] = carta2.qtdPontosTuristicos;
                break;
            case 5:
                strcpy(nomeAtributo2, "Densidade Demográfica");
                valorDosAtributosDaCarta1[1] = carta1.densidadePopulacional;
                valorDosAtributosDaCarta2[1] = carta2.densidadePopulacional;
                break;
        }

        // Imprimindo o resultado
        printf("Cartas escolhidas: %s e %s\n", carta1.cidade, carta2.cidade);
        printf("Atributos escolhidos: %s e %s\n", nomeAtributo1, nomeAtributo2);
        printf(" -> Carta %s\n", carta1.cidade);
        printf("    -> Atributo %s: %.2f\n", nomeAtributo1, valorDosAtributosDaCarta1[0]);
        printf("    -> Atributo %s: %.2f\n", nomeAtributo2, valorDosAtributosDaCarta1[1]);
        printf(" -> Carta %s\n", carta2.cidade);
        printf("    -> Atributo %s: %.2f\n", nomeAtributo1, valorDosAtributosDaCarta2[0]);
        printf("    -> Atributo %s: %.2f\n", nomeAtributo2, valorDosAtributosDaCarta2[1]);
        printf("Atributo %s: ", nomeAtributo1);
        if(atributo1 == 5) {
            if(valorDosAtributosDaCarta1[0] < valorDosAtributosDaCarta2[0])
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(valorDosAtributosDaCarta1[0] > valorDosAtributosDaCarta2[0])
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");
        } else {
            if(valorDosAtributosDaCarta1[0] > valorDosAtributosDaCarta2[0])
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(valorDosAtributosDaCarta1[0] < valorDosAtributosDaCarta2[0])
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");
        }
        printf("Atributo %s: ", nomeAtributo2);
        if(atributo2 == 5) {
            if(valorDosAtributosDaCarta1[1] < valorDosAtributosDaCarta2[1])
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(valorDosAtributosDaCarta1[1] > valorDosAtributosDaCarta2[1])
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");
        } else {
            if(valorDosAtributosDaCarta1[1] > valorDosAtributosDaCarta2[1])
                printf("Carta %s venceu!\n", carta1.cidade);
            else if(valorDosAtributosDaCarta1[1] < valorDosAtributosDaCarta2[1])
                printf("Carta %s venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");
        }
        somaDosAtributosDaCarta1 = valorDosAtributosDaCarta1[0] + valorDosAtributosDaCarta1[1];
        somaDosAtributosDaCarta2 = valorDosAtributosDaCarta2[0] + valorDosAtributosDaCarta2[1];
        printf("Soma dos atributos da Carta %s: %.2f\n", carta1.cidade, somaDosAtributosDaCarta1);
        printf("Soma dos atributos da Carta %s: %.2f\n", carta2.cidade, somaDosAtributosDaCarta2);
        printf("*\n*\n*\nResultado: ");
        if(somaDosAtributosDaCarta1 > somaDosAtributosDaCarta2)
            printf("Carta %s venceu!\n\n", carta1.cidade);
        else if(somaDosAtributosDaCarta1 < somaDosAtributosDaCarta2)
            printf("Carta %s venceu!\n\n", carta2.cidade);
        else
            printf("Empate!\n\n");
    }

    return 0;
}