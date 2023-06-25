
#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int sommet;
    int taille;
    int pile[50];
}maPile;

typedef struct{
    int tete;
    int queue;
    int taille;
    int file[50];
}maFile;

int estVideP(maPile P){
    return P.sommet==0;
}

int estVideF(maFile F){
    return F.queue==F.tete;
}

void empiler(maPile* P, int v){
    P->pile[P->sommet++]=v;
}

void enfiler(maFile* F, int v){
    F->file[F->queue++]=v;
}
int depiler(maPile* P){
    return P->pile[--P->sommet];
}

int defiler(maFile* F){
    return F->file[F->tete++];
}
int main() {
    maPile myStack;
    myStack.sommet = 0;

    empiler(&myStack, 10);
    empiler(&myStack, 20);
    empiler(&myStack, 30);
    
    printf("Stack elements: ");
    while (!estVideP(myStack)) {
        int value = depiler(&myStack);
        printf("%d ", value);
    }
    printf("\n");
    
    maFile myQueue;
    myQueue.tete = 0;
    myQueue.queue = 0;

    enfiler(&myQueue, 10);
    enfiler(&myQueue, 20);
    enfiler(&myQueue, 30);

    printf("Queue elements: ");
    while (!estVideF(myQueue)) {
        int value = defiler(&myQueue);
        printf("%d ", value);
    }
    return 0;
}
