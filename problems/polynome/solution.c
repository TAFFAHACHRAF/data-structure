#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

// la création de la structure d'un monome
struct Monome {
    double q;
    double p;
    struct Monome *next;
    struct Monome *prev;
};

// la déclaration de la fonction createPolynome() qui crée un polynome et retourne le premier élément de ce polynome.
struct Monome *createPolynome();
struct Monome *addToPolynome(double, double, struct Monome *);
void displayPolynome(struct Monome *);
struct Monome *calculateSum(struct Monome *,struct Monome *);

int main() {
    printf("hello world");
    // struct Monome *polynome1 = createPolynome();
    // polynome1 = addToPolynome(4, 7, polynome1);
    // polynome1 = addToPolynome(-7, 3, polynome1);
    // polynome1 = addToPolynome(6, 0, polynome1);
    // //displayPolynome(polynome1);

    // struct Monome *polynome2 = createPolynome();
    // polynome2 = addToPolynome(4, 7, polynome2);
    // polynome2 = addToPolynome(-7, 3, polynome2);
    // polynome2 = addToPolynome(6, 0, polynome2);
    // //displayPolynome(polynome2);

    // struct Monome *polynome3 = createPolynome();
    // polynome3=calculateSum(polynome1,polynome2);
    // displayPolynome(polynome2);

    return 0;
}

// Fonction pour créer un polynome vide (tête du polynome)
struct Monome *createPolynome() {
    struct Monome *head = (struct Monome *)malloc(sizeof(struct Monome));
    // Assurez-vous que l'allocation de mémoire a réussi
    assert(head != NULL);
    // Initialisation des champs de la tête du polynome
    head->next = NULL;
    head->prev = NULL;
    return head;
}

// Fonction pour ajouter un monome à un polynome existant
struct Monome *addToPolynome(double q, double p, struct Monome *monome) {
    struct Monome *newMonome = (struct Monome *)malloc(sizeof(struct Monome));
    // Assurez-vous que l'allocation de mémoire a réussi
    assert(newMonome != NULL);
    // Initialisation des champs du nouveau monome
    newMonome->q = q;
    newMonome->p = p;
    newMonome->next = NULL;
    newMonome->prev = NULL;

    // Vérifie si le polynome est vide
    if (monome == NULL) {
        // Si le polynome est vide, le nouveau monome devient la tête du polynome
        return newMonome;
    } else {
        // Parcourt le polynome jusqu'à la fin
        struct Monome *current = monome;
        while (current->next != NULL) {
            current = current->next;
        }
        // Ajoute le nouveau monome à la fin du polynome
        current->next = newMonome;
        newMonome->prev = current;
    }

    return monome; // Retourne la tête du polynome (peut être modifiée si le polynome était vide)
}

void displayPolynome(struct Monome *monome){
    if(monome == NULL)
        printf("la polynome est vide");
    else{
        struct Monome *ptr=createPolynome();
        ptr=monome;

        while(ptr != NULL){
            printf("%lfx^%lf + ",ptr->q,ptr->p);
            ptr=ptr->next;
        }
    }
}

struct Monome *calculateSum(struct Monome *poly1,struct Monome *poly2){
    if(poly1 == NULL){
        if(poly2 == NULL){
            return NULL;
        }
        return poly2;
    }
    struct Monome *sum=createPolynome();

    struct Monome *ptr1=createPolynome();
    ptr1=poly1;

    struct Monome *ptr2=createPolynome();
    ptr2=poly2;

    struct Monome *ptr3=createPolynome();
    ptr3=sum;
    
    while(ptr1!=NULL && ptr2!=NULL){
        ptr3->q=ptr1->q+ptr2->q;
        ptr3->p=ptr1->p+ptr2->p;

        ptr1=ptr1->next;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return sum;
}

