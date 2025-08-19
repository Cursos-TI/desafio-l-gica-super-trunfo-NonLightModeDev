#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

struct Carta
{
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
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

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
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    /*
        Comparando as cartas
    */
    printf(" Comparação de Cartas (Atributo: SUPER PODER): \n\n");
    printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.superpoder);
    printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.superpoder);

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    printf("Resultado: ");
    if(carta1.superpoder > carta2.superpoder)
        printf("Carta 1 (%s) venceu!", carta1.cidade);
    else if(carta1.superpoder < carta2.superpoder)
        printf("Carta 2 (%s) venceu!", carta2.cidade);
    else
        printf("Empate!");

    printf("\n\n");

    return 0;
}
