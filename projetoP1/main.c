#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
    // valores aleat�rios para o vetor.
    srand(time(NULL));
    for(i = 0; i < quantidade; i++){
        vet[i] = rand()%999999;
    }
    Ordenacao(vet, alg, quantidade);

    for(i=0; i < quantidade; i++){
        printf(" %d |", vet[i]);
    }

    //libera o vetor.
    free(vet);
    system("PAUSE");
    return 0;
}
