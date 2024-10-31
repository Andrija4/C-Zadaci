#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double izracunajGornji(int i){
    double rezultat = 1.0, f1=1.0, f2=1.0;

    for(int j=1; j<i; j++){

        rezultat = f1 + f2;
        f1 = f2;
        f2 = rezultat;

    }

    return rezultat;
}

double rek(int i, int n){

    double gornji, donji;

    donji = pow(2.0, n-i);
    gornji = izracunajGornji(i);

    if(i == n-1){
        if(n%2==0){
            return sqrt(gornji);
        }
        else
            return sqrt(gornji/2.0);
    }


    if(i%2==0)
        return sqrt(gornji/donji + rek(i+1, n));

    else
        return sqrt(gornji + rek(i+1, n));

}
double ite(int n){
    double rezultat=0.0;

    for(int j=n-1; j>=0; j--)
    {
        double gornji = izracunajGornji(j);
        double donji = pow(2.0, n-j);

        if(j%2==0)
            rezultat += sqrt(gornji / donji);
        else
            rezultat += sqrt(gornji);
    }

    return rezultat;
}


int main()
{
    int n;
    scanf("%d", &n);

    printf("%lf \n", rek(0, n));

    printf("%lf \n", ite(n));
    return 0;
}

//URADJEN
