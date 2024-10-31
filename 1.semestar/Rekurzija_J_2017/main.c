#include <stdio.h>
#include <stdlib.h>

double RacunajLevo(int i){

    double rezultat = 1.0;

    for(int j=1;j<=i;j++){
        rezultat += j;
    }

    return rezultat;
}


double f(int i, int n){

    if(i==n-1)
        return RacunajLevo(i);

    double desno, levo;

    desno = n*2.0-i;
    levo = RacunajLevo(i);

    return levo + desno /f(i+1, n);

}

double f_ite(int n){
    double rezultat = RacunajLevo(n-1) ;

    for(int i = n-2; i>=0; i--){
        rezultat = RacunajLevo(i) + (2.0*n-i)/ rezultat;
    }

    return rezultat;
}


int main()
{
    int n;
    scanf("%d", &n);

    printf("%lf \n", f(0, n));
    printf("%lf", f_ite(n));

    return 0;
}
//URADJEN
