#include <stdio.h>
#include <stdlib.h>

double f2(int i, int n){

    if(i==n)
        return n;

    return i+1.0/f2(i+1.0, n);

}

double f2_i(int n){
    double rezultat = n* 1.0;

    for(int i=n-1; i>0; i--)
        rezultat = i + 1.0/rezultat;

    return rezultat;
}

int main()
{

    int broj;
    scanf("%d", &broj);

    printf("%lf \n", f2(1, broj));
    printf("%lf \n", f2_i(broj));

    return 0;
}
// URADJEN
