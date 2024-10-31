#include <stdio.h>
#include <stdlib.h>

double f1_rek(int n){

    if(n==1)
        return 1.0;

    return n + 1.0 / f1_rek(n-1);
}
double f1_iter(int n){
    int i;
    double rezultat = 1.0;

    for(i=2; i<=n; i++)
        rezultat = i + 1.0/rezultat;

    return rezultat;
}


int main()
{
    int n;
    scanf("%d", &n);

    printf("%lf \n", f1_rek(n));

    printf("%lf", f1_iter(n));

    return 0;
}
