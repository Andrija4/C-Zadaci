#include <stdio.h>
#include <stdlib.h>

int main()
{

int n,m;
//Manji broj
printf("Unesite prvi broj: \n");
scanf("%d", &n);
//Veci broj
printf("Unesite drugi broj: \n");
scanf("%d", &m);

int num = (rand() % (m - n + 1)) + n;

printf("Broj je %d", num);
return 0;
}
