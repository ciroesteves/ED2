#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "menu.h"
#include "ordenacao.h"

int menuEscolhaTam(){
    int escQuant, quant;
    // Menu de Escolha do Tamanho do vetor.
    printf("Escolha a Quantidade de Elementos do Vetor:\n(1) 10\n(2) 20\n(3) 50\n(4) 100\n");
    scanf("%d", &escQuant);
    system("cls");
    // if para escolher o tamanho do vetor.
    if(escQuant == 1){
        quant = 10;
    }else if(escQuant == 2){
        quant = 20;
    }else if(escQuant == 3){
        quant = 50;
    }else if(escQuant == 4){
        quant = 100;
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

void Ordenacao(int *vet, int algoritmo, int quant){
    // switch para direcionar ao algoritmo escolhido.
        switch(algoritmo){
            case 1 :
                BubbleSort(vet, quant);
                break;
            case 2 :
                InsertionSort(vet, quant);
                break;
            case 3 :
                SelectionSort(vet, quant);
                break;
            case 4 :
                RadixSort(vet, quant);
                break;
            case 5 :
                MergeSort(vet, 0, quant-1);
                break;
            case 6 :
                QuickSort(vet, 0, quant-1);
                break;
            case 7 :
                HeapSort(vet, quant);
                break;
            default :
                printf("Seleção Inválida!");
                system("PAUSE");
                system("cls");
                algoritmo = menuEscolhaAlg();
                Ordenacao(vet, algoritmo, quant);
        }
}
