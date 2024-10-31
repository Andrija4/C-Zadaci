#include <stdio.h>
#include <stdlib.h>

double rek(int i,int n){
    if(i==n)
        return 1.0*n; //Ovo se stavlja da bi vracena vrednost bila tipa float
    return i + 1/rek(i+1,n);
}

double ite(int n){
    double rezultat = n;
    for(int i=n;i>1;i--)
        rezultat = i-1 + 1/rezultat;
    return rezultat;
}

int main()
{
    int n,i;
    printf("Unesite broj n: \n");
    scanf("%d", &n);
    printf("Rekurzivan rezultat je: %f \n", rek(1,n));
    printf("Iterativan rezultat je: %f \n", ite(n));
    return 0;
}
