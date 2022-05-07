#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
O cod recebe o nome do método de ordenação, (Selection ou Bubble).
O num de elementos do vetor e depois ler quais são esses elementos.
O cod implementado irá imprimir todos passos feito pelo sort, seja comparar (C), ou trocar (T).
Por Fim o cod imprimirá o vetor ordenado

*/

int* aloca_vetor(int n);
void ordena_selection(int *vetor, int n);
void ordena_bubble(int *vetor, int n);
int verifica_ordenacao(int *vetor, int n);
void apaga_vetor(int *vetor);

int main(){
    char metodo[15];
    scanf("%s", metodo);

    int n=0;
    scanf("%d", &n);

    int *vetor = aloca_vetor(n);

    if(strcmp(metodo, "selecao")==0){
        ordena_selection(vetor, n);

        for(int i=0; i<n; i++){
            printf("%d ", vetor[i]);
        }

    } else if(strcmp(metodo, "bolha")==0){
        ordena_bubble(vetor, n);

        for(int i=0; i<n; i++){
            printf("%d ", vetor[i]);
        }

    } else{
        printf("\n\nERROR, METODO INVALIDO!\n\n");
    }

    apaga_vetor(vetor);
    return 0;
}

int* aloca_vetor(int n){
    int *vetor = (int *) calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    return vetor;
}

void ordena_selection(int *vetor, int n){
    int menor_valor=0;
    int auxiliar_troca;
    int novo_tamanho=0;
    int menor_indice=0;

    for(int i=0+novo_tamanho; i<n-1; i++){
        menor_valor = vetor[i];
        menor_indice = i;

        for(int j=1+i; j<n; j++){  
            printf("C %d %d\n", menor_indice, j); 

            if(vetor[j]<menor_valor){
                menor_valor = vetor[j];
                menor_indice = j;
            }
        }

        if(vetor[i]>menor_valor){
            printf("T %d %d\n", i, menor_indice);

            auxiliar_troca = vetor[i];
            vetor[i] = menor_valor;
            vetor[menor_indice] = auxiliar_troca;
        }  
    }
    novo_tamanho++;
} 

void ordena_bubble(int *vetor, int n){
    int auxiliar=0;
    int armazena_ultima_troca=n-1;
    int ultima_troca=0;

    /*
        A CADA ''VARRIDA'' PELO VETOR, UMA POSIÇÃO FICARÁ CORRETA, ENTÃO ELE PERCORRERÁ
        N-1 A CADA PASSADA, A VARIAVEL NOVO_TAMANHO REPRESENTA O (N-1) NAS PASSADAS.
        OU SEJA VAI DIMINUINDO 1 A CADA VARRIDA PELO VETOR.
    */

    while(armazena_ultima_troca!=0){
        for(int i=1; i<=armazena_ultima_troca; i++){
            printf("C %d %d\n", i-1, i);

            if(vetor[i-1]>vetor[i]){
                printf("T %d %d\n", i-1, i);

                auxiliar = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = auxiliar;
                ultima_troca = i-1;

            } else{
                if(verifica_ordenacao(vetor, n)==1){
                    ultima_troca = 0;
                }
            }
        }
        armazena_ultima_troca = ultima_troca;
    }
}   

int verifica_ordenacao(int *vetor, int n){
    int aux=0;

    for(int i=1; i<n; i++){
        if(vetor[i-1]<=vetor[i]){
           aux = 1;
        } else{
            return 0;
        }
    }
    return aux;
}

void apaga_vetor(int *vetor){
    free(vetor);
}
