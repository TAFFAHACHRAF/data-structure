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

struct Node *add_Monome_To_Polynome(struct Monome monome,struct Node *);
void display_Polynome(struct Node *);
struct Node *calculate_Sum_Of_Two_Polynome(struct Node *,struct Node *);
struct Node *calculate_Multiplication_Of_TwoPolynome(struct Node *,struct Node *);
void solve_Polynome(struct Node *);