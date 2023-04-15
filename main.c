// Escreva um programa que implemente uma pilha em um vetor com capacidade para 5 números inteiros. Um menu deve ser apresentado com as seguintes opções:

// # MENU #

// [1] Adicionar elemento na pilha

// [2] Remover elemento da pilha

// [3] Buscar elemento na pilha

// [4] Listar os elemento da pilha

// [5] Sair

// Observações:

// - Cuide da necessidade de verificar se a pilha está vazia ou se a pilha está cheia em conforme a opção

// selecionada no menu.

// - Para a opção 3, caso o elemento exista na pilha, deverá ser mostrado em qual posição da pilha o

// mesmo se encontra. Caso contrário, deverá ser mostrada a mensagem "Elemento não encontrado".
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_SIZE 5 // Alocação estática devido ao enunciado;

typedef struct{
    int topo; // Indica o indice do último elemento da pilha
    int item[MAX_SIZE];
} Pilha_t;

// Iniciar a pilha setando o topo igual a -1
void inicia_pilha(Pilha_t * ptr){
    ptr->topo = -1;
}

// Indicar se minha pilha está vazia
bool is_empty(Pilha_t * ptr){
    return ptr->topo == -1 ? true : false;
}

// Indicar se minha pilha está Cheia
bool is_full(Pilha_t * ptr){
    return ptr->topo == (MAX_SIZE - 1) ? true : false;
}

// Adicionar um elemento na minha Pilha
int push(Pilha_t * ptr, int ele){
    if(is_full(ptr)){
        printf("ERRO!!! Pilha Cheia.");
        exit(0);
    }
    else
    {
        ptr->topo++;
        ptr->item[ptr->topo] = ele;
        return ptr->topo;
        
    }
}

// Removendo o último elemento da minha pilha
int pop(Pilha_t * ptr){
    int aux;
    if(is_empty(ptr)){
        printf("ERRO!!! Pilha Vazia.");
        exit(0);
    }
    else
    {
        aux = ptr->item[ptr->topo];
        ptr->topo--;
        return aux;
    }
}

// Buscar elementos na minha Pilha
int search(Pilha_t * ptr, int ele, int topo){
    if(ptr->item[topo] == ele){
        return topo;
    }
    else
    {
        if(topo >= 0){
            topo--;
            return search(ptr, ele, topo);
        }
    }
    return -1;
}

// Listar os elementos da minha pilha
void listar(Pilha_t * ptr){
    for(int i = 0; i <= ptr->topo; ++i){
        printf("[%i] -> %i\n", i, ptr->item[i]);
    }
}

// Construin o Menu;
void constroi_menu(){

    printf("=========================================\n");
    printf("                #MENU#                   \n");
    printf("\n");
    printf("(1). Adicionar elemento na Pilha.\n");
    printf("(2). Remover elemento da pilha.\n");
    printf("(3). Buscar elemento da pilha.\n");
    printf("(4). Listar elemento da pilha.\n");
    printf("(5). Sair\n");
    printf("=========================================\n");

}

int main(){

    int n = 0;
    Pilha_t * pilha = (Pilha_t *) malloc(sizeof(Pilha_t));
    
    inicia_pilha(pilha);

    while(1){
         constroi_menu();
    
        switch ((char) getchar())
        {
        case '1':
            printf("Qual elemento voce quer adicionar: \t");
            scanf("%i", &n);
            getchar();

            printf("Elemento %i adicionado na posicao [%i].\n", n, push(pilha, n));
            Sleep(1000);
            system("cls");
            break;

        case '2':
            printf("Elemento: %i SAIU!!!\n", pop(pilha));
            Sleep(1000);
            system("cls");
            break;

        case '3':
            printf("Qual elemento voce quer encontrar: \t");
            scanf("%i", &n);
            getchar();

            if(search(pilha, n, pilha->topo) != -1){
                printf("Elemento %i, encontrado na posicao [%i].\n", n, search(pilha, n, pilha->topo));
            }
            else
            {
                printf("ERRO!!! Elemento nao encontrado.\n");
            }
            Sleep(1000);
            system("cls");
            break;

        case '4':
            listar(pilha);
            Sleep(1000);
            system("cls");
            break;

        case '5':
            printf("FALOU MEU PARCEIRO.");
            system("cls");
            exit(1000);
        
        default:
            system("cls");
            break;
        }
    }
 
 
    return 0;
}