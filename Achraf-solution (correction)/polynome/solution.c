#include "solution.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>


struct Monome create_Monome(double coefficient,double puissance){
    struct Monome monome;
    monome.coefficient=coefficient;
    monome.puissance=puissance;
    return monome;
}

struct Node *create_Polynome(){
    struct Monome monome=create_Monome((double)0,(double)0);
    struct Node *newPolynome;
    newPolynome = (struct Node*)malloc(sizeof(struct Node));
    newPolynome->monome=monome;
    newPolynome->next=NULL;
    newPolynome->prev=NULL;
}

struct Node *add_Monome_To_Polynome(struct Monome monome, struct Node *head) {
    struct Node *temp;
    temp = head;

    if (temp->monome.coefficient == 0) {
        temp->monome=monome;
        return head;
    } 
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        struct Node *newNode = create_Polynome();
        newNode->monome = monome;
        newNode->next = NULL;
        newNode->prev = temp;
        
        temp->next = newNode;
        return head;
    }
}


void display_Polynome(struct Node *head){
    struct Node *temp;
    temp=head;
    while(temp != NULL){
        printf("%lf(X^%lf) +",temp->monome.coefficient,temp->monome.puissance);
        temp=temp->next;
    }
}
struct Node *calculate_Sum_Of_Two_Polynome(struct Node *,struct Node *);
struct Node *calculate_Multiplication_Of_TwoPolynome(struct Node *,struct Node *);
void solve_Polynome(struct Node *);