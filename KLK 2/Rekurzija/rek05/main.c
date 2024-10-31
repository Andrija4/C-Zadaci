#include <stdio.h>
#include <stdlib.h>

double rek(int n){
    if(n==1)
        return 1;
    return n + 1/rek(n-1);
}

double ite(int n){
    double rezultat = 1;
    for(int i=2;i<=n;i++){
        rezultat = 1/rezultat + i;
    }
    return rezultat;
}

int main()
{
    int n;
    printf("Unesite cifru n: \n");
    scanf("%d", &n);
    printf("Rekurzivno: %f\n", rek(n));
    printf("Iterativno: %f\n", ite(n));
    return 0;
}
