#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
//1)
struct Monome{
	int coeff;
	int degre;
};

//2
struct PolyNode{
	struct Monome* monome;
	struct PolyNode* next;
	struct PolyNode* prev;
};

//3

struct PolyNode* createNode(int coeff, int degre) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->monome = (struct Monome*)malloc(sizeof(struct Monome));
    newNode->monome->coeff = coeff;
    newNode->monome->degre = degre;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct PolyNode* sommePolynome(struct PolyNode* poly1Head, struct PolyNode* poly2Head) {
    struct PolyNode* poly1 = poly1Head;
    struct PolyNode* poly2 = poly2Head;
    struct PolyNode* resultHead = NULL;
    struct PolyNode* resultTail = NULL; 
    while (poly1 != NULL) {
        while (poly2 != NULL) {
            if (poly1->monome->degre == poly2->monome->degre) {
                int value = poly1->monome->coeff + poly2->monome->coeff;
                int degre = poly1->monome->degre;
                struct PolyNode* newNode = createNode(value, degre);
                
                if (resultHead == NULL) {
                    resultHead = newNode;
                    resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    newNode->prev = resultTail;
                    resultTail = newNode;
                }                
            }
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
        poly2 = poly2Head;
    }
    return resultHead;
}

//4
struct PolyNode* produitPolynome(struct PolyNode* poly1Head, struct PolyNode* poly2Head) {
    struct PolyNode* poly1 = poly1Head;
    struct PolyNode* poly2 = poly2Head;
    struct PolyNode* resultHead = NULL;
    struct PolyNode* resultTail = NULL; 
    while (poly1 != NULL) {
        while (poly2 != NULL) {
                int value = poly1->monome->coeff * poly2->monome->coeff;
                int degre = poly1->monome->degre * poly2->monome->degre;
                struct PolyNode* newNode = createNode(value, degre);
                if (resultHead == NULL) {
                    resultHead = newNode;
                    resultTail = newNode;
                } else {
                    resultTail->next = newNode;
                    newNode->prev = resultTail;
                    resultTail = newNode;
                }  
                poly2 = poly2->next;
            }
	 poly1 = poly1->next;
        poly2 = poly2Head;
        }
      
	return resultHead;
    }
    

//5
void solutionPolynome(struct PolyNode* polyHead) {
    int a = 0, b = 0, c = 0;
    struct PolyNode* current = polyHead;
    while (current != NULL) {
        int coeff = current->monome->coeff;
        int degre = current->monome->degre;
        switch (degre) {
            case 2:
                a += coeff;
                break;
            case 1:
                b += coeff;
                break;
            case 0:
                c += coeff;
                break;
        }
        current = current->next;
    }
    if (a == 0 && b == 0) {
        printf("Pas 2eme degre\n");
        return;
    }
    if (a == 0) {
        double x = -c / (double)b;
        printf("Une seule solution:\n");
        printf("x = %.2f\n", x);
        return;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Deux solutions:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("Une seule solution:\n");
        printf("x = %.2f\n", x);
    } else {
        printf("Aucune solution.\n");
    }
}
