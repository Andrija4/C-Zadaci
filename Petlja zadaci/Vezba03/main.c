#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,s,o,m,d,k;
    printf("Unesi dva cela broja:\n");
    scanf("%d %d",&a ,&b);

    s=a+b;
    o=a-b;
    m=a*b;
    k=a/b;
    d=a%b;

    printf("Rezultati kod \nSabiranja:%d \nOduzimanja:%d \nMnozenja:%d \nDeljenja:%d \nOstatak:%d \n",s ,o ,m ,k ,d);

    return 0;
}
