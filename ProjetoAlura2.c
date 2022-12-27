#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("***********************************\n");
    printf("*BEM-VINDOS AO JOGO DA ADIVINHACAO*\n");
    printf("***********************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100; // variável do número  secreto
    int chute; // variável dos chutes
    int tentativas = 1;
    double pontos = 1000; //Variável pontos inciando em 1000

    while(1) { //Faz com que o loop seja sempre verdadeiro ou seja o loop vira infinito

        printf("\nTentativa %d\n", tentativas);
        printf("\nInforme o seu chute: ");

        scanf("%d", &chute);
        printf("\nO seu chute foi: %d\n", chute);

        if (chute < 0){  // Se o chute for mernor que 0 ou seja negativo vai imprimir a mensagem abaixo
            printf("Voce nao pode chutar numeros negativos!\n");

            continue; // essa função faz com que o loop não seja quebrado fazendo os próximos trechos do código funcionarem
        }            // Até que se digite um chute maior ou igual a 0, ou seja ele não dar continuidade a tudo que está 
                    //ai embaixo, mas também ele não para o código, ele sobe lá pra cima caso o numero seja negativo,
                   // e vai para o c++ lá em cima
        
        int acertou, maior;  

        acertou = (chute == numerosecreto);
        maior = (chute > numerosecreto);
        

        if (acertou) {
            printf("\nParabens, voce acertou o numero secreto!\n\n");

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

    printf("\nFim do jogo!\n\n");
    printf("Voce acertou em %d tentativas\n\n", tentativas);
    printf("Total de pontos: %.1f\n\n", pontos); // total de pontos que o jogador fez

    return 0;
}
