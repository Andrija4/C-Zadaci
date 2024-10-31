#include <stdio.h>
#include <stdlib.h>

int main()
{

    //Palindrom je broj koji je sa obe strane isti npr. 1221 ili 3443

    int a,b=0,c,i;

    printf("Unesi cetvorocifreni broj: \n");
    scanf("%d", &a);
    c=a;
    for(i=4;i>0;i--){
        b=b*10+c%10;
        c=c/10;
    }

    if(a==b)
        printf("DA");
    else
        printf("NE");

    return 0;
}
