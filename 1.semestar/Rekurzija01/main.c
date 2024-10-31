#include <stdio.h>
#include <stdlib.h>

int pow_rek(int a, int b){

int rez;
if (b==0)
    return 1;

rez = a * pow_rek(a,b-1);

return rez;
}

int main()
{
    int broj, pow, rez;

    printf("Unesite broj koji zelite da stepenujete: \n");
    scanf("%d", &broj);

    printf("Unesi pow: \n");
    scanf("%d", &pow);

    rez = pow_rek(broj, pow);
    printf("Rezultat je: %d\n ", rez);
    return 0;
}
//URADJEN
