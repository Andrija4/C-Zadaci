#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n){
    if(n==1)
        return 1;
    return sqrt(n+rek(n-1));
}

double ite(int n){
    double resenje=1;
    for(int i=2;i<=n;i++)
        resenje = sqrt(i+resenje);
    return resenje;
}

int main()
{
    int n;
    printf("Ubacite n: \n");
    scanf("%d", &n);
    printf("Rekurzivno: %f \n", rek(n));
    printf("Iterativno: %f", ite(n));
    return 0;
}
