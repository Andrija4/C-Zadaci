#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("Unesite duzinu u stopama: \n");
    scanf("%f", &a);
    b=a*30.48;
    printf("Duzina u centimetrima je:\n\%.2f", b);

    return 0;
}
