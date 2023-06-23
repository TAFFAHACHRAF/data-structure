# Problem
  ![Problem](images/problem.jpg)

## solution :
`
struct Monome {
    double coefficient;
    double puissance;
};

struct Node {
    struct Monome monome;
    struct Node *next;
    struct Node *prev;
};

struct Monome create_Monome(double,double);
struct Node *create_Polynome();
struct Node *add_Monome_To_Polynome(struct Monome monome,struct Node *);
void display_Polynome(struct Node *);
struct Node *calculate_Sum_Of_Two_Polynome(struct Node *,struct Node *);
struct Node *calculate_Multiplication_Of_TwoPolynome(struct Node *,struct Node *);
void solve_Polynome(struct Node *);
`