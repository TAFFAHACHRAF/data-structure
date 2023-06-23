struct Monome {
    double coefficient;
    double puissance;
    struct Monome *next;
    struct Monome *prev;
};

struct Monome *createPolynome();
struct Monome *addToPolynome(double, double, struct Monome *);
void displayPolynome(struct Monome *);
struct Monome *calculateSum(struct Monome *,struct Monome *);
struct Monome *calculateMultiplication(struct Monome *,struct Monome *);
void solvePolynome(struct Monome *);