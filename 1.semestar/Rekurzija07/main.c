#include <stdio.h>
#include <stdlib.h>

double f3(int n){

    if(n==1)
        return 1;

    return sqrt(n + f3(n-1));
}
double f3_i(int n){

    double rezultat = sqrt(1);
    for(int i=2; i<=n; i++)
        rezultat = sqrt(i + rezultat);

    return rezultat;
}

int main()
{
    int broj;
    scanf("%d", &broj);

    printf("%lf \n", f3(broj));
    printf("%lf \n", f3_i(broj));

    return 0;
}
