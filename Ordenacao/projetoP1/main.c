#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "ordenacao.h"
#include "menu.h"

int main()
{
    // setlocale para caracteres especiais e defini��o de vari�veis.
    setlocale(LC_ALL,"Portuguese");
    int quantidade, alg, i, x, aux;
    int *vet;
    double tempo, media, soma;
    // fun��o do menu de algoritmo do vetor.
    alg = menuEscolhaAlg();
    // fun��o escolha do tamanho do vetor.
    quantidade = menuEscolhaTam();
    // alocando memoria para o vetor.
    vet = (int*) malloc (quantidade * sizeof(int));
    if (vet==NULL) {
        printf("Mem�ria insuficiente!\n");
        exit(1);
    }
    // repete o teste 10x .
    for(x=0;x<10;x++){
        // valores aleat�rios para o vetor.
        srand(time(NULL));
        for(i = 0; i < quantidade; i++){
            vet[i] = rand()%999999;
        }
        tempo = Ordenacao(vet, alg, quantidade);
        soma = soma + tempo;
    }
    // Resultados dos Tempos.
    media = soma/10.00;

    printf("\n========== Vetor Aleat�rio ===========\n");
    printf("\nM�dia de Tempo : %f\n", media);

    printf("\n=========== Vetor Ordenado ===========\n");
    // cria��o do vetor j� ordenado.
    for(i=0;i<quantidade;i++){
        vet[i] = i+1;
    }
    tempo = Ordenacao(vet, alg, quantidade);

    printf("\n========== Vetor Invertido ===========\n");
    // cria��o do vetor invertido.
    aux = quantidade;
    for(i=0;i<quantidade;i++){
        vet[i] = aux--;
    }
    tempo = Ordenacao(vet, alg, quantidade);

    //libera o vetor.
    free(vet);
    system("PAUSE");
    return 0;
}
