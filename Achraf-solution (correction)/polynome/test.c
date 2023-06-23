#include "solution/solution.c"

int main() {
    struct Node *head1,*head2,*sum,*power;
    head1=create_Polynome();
    head2=create_Polynome();

    struct Monome monome1,monome2,monome3,monome4;
    monome1.coefficient=(double)2;
    monome1.puissance=(double)4;

    monome2.coefficient=(double)-5;
    monome2.puissance=(double)2;

    monome3.coefficient=(double)3;
    monome3.puissance=(double)3;

    monome4.coefficient=(double)1;
    monome4.puissance=(double)2;


    head1=add_Monome_To_Polynome(monome1,head1);
    head1=add_Monome_To_Polynome(monome2,head1);

    head2=add_Monome_To_Polynome(monome3,head2);
    head2=add_Monome_To_Polynome(monome4,head2);
    
    //solve_Polynome(head1);
    
    printf("display poly 1. \n");
    display_Polynome(head1);

    printf("display poly 2. \n");
    display_Polynome(head2);

    sum=calculate_Sum_Of_Two_Polynome(head1,head2);

    printf("display the sum of poly1 and poly2. \n");
    display_Polynome(sum);

    power=calculate_Multiplication_Of_TwoPolynome(head1,head2);

    printf("display the power of poly1 and poly2. \n");
    display_Polynome(power);


    return 0;
}
