#include <stdio.h>
#include <stdlib.h>

int zbir_cif_rek(int a){
int zbir;
if(a==0)
    return 0;

zbir = a%10 + zbir_cif_rek(a/10);
return zbir;
}

int main()
{
    int broj, suma;

    printf("Unesite celi broj: \n");
    scanf("%d", &broj);

    suma = zbir_cif_rek(broj);
    printf("Suma je: %d\n", suma);

    return 0;
}
//URADJEN
