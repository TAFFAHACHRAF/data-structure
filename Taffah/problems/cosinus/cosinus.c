#include <stdio.h>
#include <math.h>
#include <assert.h>

double canculeCosX(double x,int n);
int calculFactoriel(int nbr);
int calculFactorielRcursive(int nbr);


int main() {
   double x;
   int n;

  printf("Entrer svp x : ");
  scanf("%lf",&x);

  printf("Entrer l'ordre n : ");
  scanf("%d",&n);

  printf("Cos(%lf) est %lf",x,canculeCosX(x,n));
    printf("%d",&calculFactorielRcursive(1,5));
   return 0;
}


double canculeCosX(double x,int n){
    assert(n>0);

    double result;
    for(int i=0;i<=n;i++){
        result += pow(-1,i) * (pow(x,2*i) / calculFactoriel(2*i));
    }
    return result;
}

int calculFactoriel(int nbr){
    int result=1;
    if(nbr==0 || nbr==1){
        return 1;
    }
    for(int i=2;i<=nbr;i++){
        result*=i;//result=result*i
    }
    return result;
}


int calculFactorielRcursive(int n){
    if(n <= 1)
        return 1;
    return n * calculFactorielRcursive(n-1); 
}
