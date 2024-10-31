#include <stdio.h>
#include <stdlib.h>

double rek(int i, int n){
    double sabirak = 1+i*(i-1)/2;
    double brojilac = n*2-i+1;
    if(i==n)
        return sabirak;
    return sabirak + brojilac/rek(i+1,n);
}
double ite(int n){
    int i;
    double sabirak = 1;

    //Ovde racunamo poslednji sabirak
    for(i=0;i<n;i++)
        sabirak = sabirak + i;

    double rez = sabirak;

    for(i;i>0;i--){
        sabirak = sabirak-i;
        rez = sabirak+(n*2-i+1)/rez;
    }
    return rez;
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
