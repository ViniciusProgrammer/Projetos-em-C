#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("***********************************\n");
    printf("*BEM-VINDOS AO JOGO DA ADIVINHACAO*\n");
    printf("***********************************\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100; 
    int chute; 
    int tentativas = 1;
    double pontos = 1000; 

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n\n");
    printf("(1) facil (2) medio (3) dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);


    int numerotentativas;

    if (nivel == 1){
        numerotentativas = 20;
    }
    else if (nivel == 2) {
        numerotentativas = 15;
    }
    else {
        numerotentativas = 6;
    }

    for(int i = 1; i <= numerotentativas; i++) { 

        printf("\nTentativa %d\n", tentativas);
        printf("\nInforme o seu chute: ");

        scanf("%d", &chute);
        printf("\nO seu chute foi: %d\n", chute);

        if (chute < 0){  
            printf("Voce nao pode chutar numeros negativos!\n");

            continue; 
        }             

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        

        if (acertou) {
            break;
        }
        else if (maior) {
            printf("\nO seu chute foi maior que o numero secreto!. Tente novamente!\n");
        }
        else {
            printf("\nO seu chute foi menor que o numero secreto!. Tente novamente!\n");
        }
        tentativas = tentativas + 1;

        double pontosperdidos = (chute - numerosecreto) / (double)2;

        if(pontosperdidos < 0) {
            pontosperdidos = pontosperdidos * -1;
        }
        pontos = pontos - pontosperdidos; 
    }
    printf("\nFim de jogo!\n");

    if (acertou) {
        printf("\nVoce ganhou!\n");
        printf("\nVoce acertou em %d tentativas\n\n", tentativas);
        printf("Total de pontos: %.1f\n\n", pontos);
    } 
    else{
        printf("\nVoce errou! Tente de novo!\n\n");
    }

    return 0;
}
