#include "solution.c"

int main() {
    struct Node *newPolynome;
    newPolynome=create_Polynome();
    printf("coefficient:%lf  puissance:%lf",newPolynome->monome.coefficient,newPolynome->monome.puissance);
    return 0;
}
