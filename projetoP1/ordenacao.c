#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

void BubbleSort(int *vetor, int fim){
	int pos,continua,aux;
	do{
		continua = 0;
		for(pos = 0; pos < fim - 1; pos++){
			if(vetor[pos] > vetor[pos+1]){
				aux = vetor[pos];
				vetor[pos] = vetor[pos+1];
				vetor[pos+1] = aux;
				continua = pos;
			}
		}
		fim--;
	}while(continua != 0);
}

void InsertionSort(int *vetor, int fim){
	int pos, pos2, aux;
	for(pos = 1; pos < fim; pos++){
		aux = vetor[pos];
		for(pos2 = pos;(pos2 > 0) && (aux < vetor[pos2-1]); pos2--){
			vetor[pos2] = vetor[pos2-1];
		}
		vetor[pos2] = aux;
	}
}

void SelectionSort(int *vetor, int fim){
	int pos, pos2, aux, menor;
	for(pos = 0;pos < fim - 1 ; pos++){
		menor = pos;
		for(pos2 = pos + 1; pos2 < fim; pos2++){
			if(vetor[pos2] < vetor[menor]){
				menor = pos2;
			}
		}
		if(pos != menor){
			aux = vetor[pos];
			vetor[pos] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}

void RadixSort(int *v, int tamanho){
  // Descobre o valor de dígito máximo dos numeros
  // Precisamos dessa etapa para saber com quantos dígitos máximos iremos trabalhar
  int num = tamanho;
  int num_digitos = 0;
  do {
    num_digitos++;
    num /= 10;
  } while(num != 0);

  // Algoritmo de ordenaçao
  int i, j, w, d, posicao;
  int count[10];
  int *aux = (int *)malloc(tamanho * sizeof(int));

  for (w = 0; w < num_digitos; w++){
    for (j = 0; j < 10; j++)
      count[j] = 0;
    for (i = 0; i < tamanho; i++){
      d = (int)(v[i] / (pow(10, w))) % 10;
      count[d]++;
    }
    for (j = 1; j < 10; j++)
      count[j] += count[j - 1];
    for (i = tamanho - 1; i >= 0; i--) {
      d = (int)(v[i]/ pow(10,w)) % 10;
      count[d] = count[d] - 1;
      posicao = count[d];
      aux[posicao] = v[i];
    }
    for (int i = 0; i< tamanho; i++) {
      v[i] = aux[i];
    }
  }
}

void Merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp == NULL){
        printf("ERRO NO MALLOC");
        exit(1);
    }

    if(temp != NULL){
        for(i = 0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                    else
                        temp[i] = v[p2++];
                    if(p1>meio) fim1=1;
                    if(p2>fim) fim2=1;
                }
                else{
                    if(!fim1)
                        temp[i] = v[p1++];
                    else
                        temp[i] = v[p2++];
            }
        }
        for(j = 0, k =  inicio; j<tamanho; j++, k++){
            v[k] =  temp[j];
        }
    }
    free(temp);
}

void MergeSort(int *v, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        MergeSort(v,inicio,meio);
        MergeSort(v,meio+1,fim);
        Merge(v, inicio, meio, fim);
    }
}

void QuickSort(int *vetor, int esquerda, int direita){
    int i, j, meio, troca;
    i = esquerda;
    j= direita;
    meio = vetor[(esquerda+direita)/2];

    while(i <= j){
        while(vetor[i]<meio && i<direita){
            i++;
        }
        while(vetor[j]>meio && j>esquerda){
            j--;
        }
        if(i<=j){
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
            i++;
            j--;
        }
    }
    if(j>esquerda){
        QuickSort(vetor, esquerda, j);
    }
    if(i<direita){
        QuickSort(vetor, i, direita);
    }
}

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void HeapSort(int *vet, int N) {
    int i, aux;
    for(i=(N-1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}

