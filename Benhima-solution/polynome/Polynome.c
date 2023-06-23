#include <stdio.h>
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
int main() {
    // Create polynomial 1: 2x^2 + 3x + 1
    struct PolyNode* poly1Head = createNode(2, 2);
    struct PolyNode* node1 = createNode(3, 1);
    struct PolyNode* node2 = createNode(1, 0);
    poly1Head->next = node1;
    node1->prev = poly1Head;
    node1->next = node2;
    node2->prev = node1;

    // Create polynomial 2: 4x^2 + 2x + 3
    struct PolyNode* poly2Head = createNode(4, 2);
    struct PolyNode* node3 = createNode(2, 1);
    struct PolyNode* node4 = createNode(3, 0);
    poly2Head->next = node3;
    node3->prev = poly2Head;
    node3->next = node4;
    node4->prev = node3;

    // Test polynomial addition
    printf("Polynomial addition:\n");
    struct PolyNode* sumResult = sommePolynome(poly1Head, poly2Head);
    struct PolyNode* sumCurrent = sumResult;
    while (sumCurrent != NULL) {
        printf("%dx^%d ", sumCurrent->monome->coeff, sumCurrent->monome->degre);
        sumCurrent = sumCurrent->next;
    }
    printf("\n");

    // Test polynomial multiplication
    printf("Polynomial multiplication:\n");
    struct PolyNode* productResult = produitPolynome(poly1Head, poly2Head);
    struct PolyNode* productCurrent = productResult;
    while (productCurrent != NULL) {
        printf("%dx^%d ", productCurrent->monome->coeff, productCurrent->monome->degre);
        productCurrent = productCurrent->next;
    }
    printf("\n");

    // Test polynomial equation solution
    printf("Polynomial equation solution:\n");
    solutionPolynome(poly1Head);

    // Free memory
    // TODO: Implement a function to free the memory allocated for the linked lists

    return 0;
}
