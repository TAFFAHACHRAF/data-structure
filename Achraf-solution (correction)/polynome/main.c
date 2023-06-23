#include "solution.c"

int main() {
    struct Node *head;
    head=create_Polynome();

    struct Monome monome1,monome2,monome3,monome4;
    monome1.coefficient=(double)5;
    monome1.puissance=(double)4;

    monome2.coefficient=(double)5;
    monome2.puissance=(double)3;

    monome3.coefficient=(double)5;
    monome3.puissance=(double)2;

    monome4.coefficient=(double)5;
    monome4.puissance=(double)1;

    head=add_Monome_To_Polynome(monome1,head);
    head=add_Monome_To_Polynome(monome2,head);
    head=add_Monome_To_Polynome(monome3,head);
    head=add_Monome_To_Polynome(monome4,head);

    display_Polynome(head);

    return 0;
}
