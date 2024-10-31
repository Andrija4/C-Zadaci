#include <stdio.h>
#include <stdlib.h>

double f4(int i, int n){

    if(n==i)
        return sqrt(n);

    return sqrt(i + f4(i+1, n));
}
double f4_i(int n){
    double rezultat = sqrt(n);

    for(int i=n-1; i>0; i--)
        rezultat = sqrt(i + rezultat);

    return rezultat;
}


int main()
{
    int broj;
    scanf("%d", &broj);

    printf("%lf \n", f4(1 , broj));
    printf("%lf \n", f4_i(broj));


    return 0;
}
