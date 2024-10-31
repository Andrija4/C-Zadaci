#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,m,k,f;

    printf("Unesi prvi broj: \n");
    scanf("%d", &n);

    printf("Unesi drugi broj: \n");
    scanf("%d", &m);

    printf("Unesi delioc: \n");
    scanf("%d", &k);

    while(f%k!=0)
        f = (rand() % (m - n + 1)) + n;

    printf("Broj je \n %d", f);
    return 0;

}
