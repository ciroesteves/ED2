#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "menu.h"
#include "ordenacao.h"

int menuEscolhaTam(){
    int escQuant, quant;
    // Menu de Escolha do Tamanho do vetor.
    printf("Escolha a Quantidade de Elementos do Vetor:\n(1) 10000\n(2) 50000\n(3) 100000\n(4) 200000\n(5) 500000\n(6) 1000000\n");
    scanf("%d", &escQuant);
    system("cls");
    // if para escolher o tamanho do vetor.
    if(escQuant == 1){
        quant = 10000;
    }else if(escQuant == 2){
        quant = 50000;
    }else if(escQuant == 3){
        quant = 100000;
    }else if(escQuant == 4){
        quant = 200000;
    }else if(escQuant == 5){
        quant = 500000;
    }else if(escQuant == 6){
        quant = 1000000;
    }else{
        printf("Seleção Inválida!");
        system("PAUSE");
        system("cls");
        menuEscolhaTam();
    }
    return quant;
}

int menuEscolhaAlg(){
    int escAlg;
    // Menu de Escolha do Algoritmo de Ordenação Desejado.
    printf("Escolha o Algoritmo de Ordenação:\n(1) BubbleSort\n(2) InsertionSort\n(3) SelectionSort\n");
    printf("(4) RadixSort\n(5) MergeSort\n(6) QuickSort\n(7) HeapSort\n");
    scanf("%d", &escAlg);
    system("cls");
    // if para escolher o tamanho do vetor.
    if(escAlg > 0 && escAlg < 8){
        return escAlg;
    }else{
        printf("Seleção Inválida!");
        system("PAUSE");
        system("cls");
        menuEscolhaAlg();
        return 0;
    }
}

double Ordenacao(int *vet, int algoritmo, int quant){
    double deltaT;
    struct timeval Tempo_antes, Tempo_depois;
    // switch para direcionar ao algoritmo escolhido.
        switch(algoritmo){
            case 1 :
                gettimeofday(&Tempo_antes, NULL);
                BubbleSort(vet, quant);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 2 :
                gettimeofday(&Tempo_antes, NULL);
                InsertionSort(vet, quant);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 3 :
                gettimeofday(&Tempo_antes, NULL);
                SelectionSort(vet, quant);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 4 :
                gettimeofday(&Tempo_antes, NULL);
                RadixSort(vet, quant);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 5 :
                gettimeofday(&Tempo_antes, NULL);
                MergeSort(vet, 0, quant-1);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 6 :
                gettimeofday(&Tempo_antes, NULL);
                QuickSort(vet, 0, quant-1);
                gettimeofday(&Tempo_depois, NULL);
                break;
            case 7 :
                gettimeofday(&Tempo_antes, NULL);
                HeapSort(vet, quant);
                gettimeofday(&Tempo_depois, NULL);
                break;
            default :
                printf("Seleção Inválida!");
                system("PAUSE");
                system("cls");
                algoritmo = menuEscolhaAlg();
                Ordenacao(vet, algoritmo, quant);
        }
    // cálculo dos tempos de execução.
    deltaT = (Tempo_depois.tv_sec + (Tempo_depois.tv_usec/1000000.00)) - (Tempo_antes.tv_sec + (Tempo_antes.tv_usec/1000000.00));
    printf("\nTempo: %f\n", deltaT);
    return deltaT;
}
