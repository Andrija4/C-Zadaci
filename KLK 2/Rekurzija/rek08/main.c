#include <stdio.h>
#include <stdlib.h>

double rek(int i, int n){
    if(i==n)
        return sqrt(n);
    return sqrt(i+rek(i+1,n));
}
double ite(int n){
    double rezultat = sqrt(n);
    for(int i=n-1;i>0;i--)
        rezultat = sqrt(i+rezultat);
    return rezultat;
}

int main()
{
    int n;
    printf("Unesite n: \n");
    scanf("%d", &n);
    printf("Rekurzivno n: %f\n", rek(1,n));
    printf("Iterativno n: %f\n", ite(n));
    return 0;
}
