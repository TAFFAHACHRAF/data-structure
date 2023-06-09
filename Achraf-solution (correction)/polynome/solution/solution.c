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
    return newPolynome;
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
        printf("%lfX^%lf",temp->monome.coefficient,temp->monome.puissance);
        temp=temp->next;

        if(temp && temp->monome.coefficient>=0)
            printf("+");
    }
    printf("\n");
}

struct Node *calculate_Multiplication_Of_TwoPolynome(struct Node *head1, struct Node *head2) {
    struct Node *temp1, *temp2, *result = create_Polynome();
    temp1 = head1;
    temp2 = head2;

    // Iterate over each term of the first polynomial
    while (temp1 != NULL) {
        while (temp2 != NULL) {
            // Multiply the coefficients and add the powers
            struct Monome multipliedMonome = create_Monome(temp1->monome.coefficient * temp2->monome.coefficient,
                                                           temp1->monome.puissance + temp2->monome.puissance);
            // Add the multiplied term to the result polynomial
            result = add_Monome_To_Polynome(multipliedMonome, result);

            temp2 = temp2->next;
        }

        temp2 = head2;  // Reset temp2 to the beginning of the second polynomial
        temp1 = temp1->next;
    }

    return result;
}

struct Node* calculate_Sum_Of_Two_Polynome(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    struct Node* result = create_Polynome();
    
    while (temp1 && temp2) {
        if (temp1->monome.puissance == temp2->monome.puissance) {
            double c = temp1->monome.coefficient + temp2->monome.coefficient;
            double p = temp1->monome.puissance;
            result = add_Monome_To_Polynome(create_Monome(c, p), result);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->monome.puissance > temp2->monome.puissance) {
            double c = temp1->monome.coefficient;
            double p = temp1->monome.puissance;
            result = add_Monome_To_Polynome(create_Monome(c, p), result);
            temp1 = temp1->next;
        }
        else {
            double c = temp2->monome.coefficient;
            double p = temp2->monome.puissance;
            result = add_Monome_To_Polynome(create_Monome(c, p), result);
            temp2 = temp2->next;
        }
    }
        
    return result;
}

void solve_Polynome(struct Node *head) {
    struct Node *temp;
    temp = head;
    if (temp->monome.puissance > 2) {
        printf("This is not a second-degree polynomial.\n");
    }
    else{
        // delta = b * b - 4 * a * c
        double a = temp->monome.coefficient;
        double b = temp->next->monome.coefficient;
        double c = temp->next->next->monome.coefficient;
        double delta = pow(b, 2) - 4 * a * c;

        if (delta < 0) {
            printf("This equation has no solution in R.\n");
        }
        else if (delta == 0) {
            double s = -b / (2 * a);
            printf("This equation has a double root in R: s = %lf\n", s);
        }
        else {
            double s1 = (-b - sqrt(delta)) / (2 * a);
            double s2 = (-b + sqrt(delta)) / (2 * a);

            printf("This equation has these solutions in R: s1 = %lf, s2 = %lf\n", s1, s2);
        }
    }
}
