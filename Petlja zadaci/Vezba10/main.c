#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,i;
    printf("Unesi cetvorocifreni broj: \n");
    scanf("%d", &n);

    for(i=4;i>0;i--)
    {
        printf("%d ", n%10);
        n=n/10;
    }


    return 0;
}
