#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    int b,i,g,zbir=0;

    printf("Unesi trocifren broj: \n");
    scanf("%d", &b);
    g=b;

    for(i=0;i<3;i++){

        zbir += pow(b%10,3);
        b=b/10;
    }
    if(zbir==g)
        printf("DA");
    else
        printf("NE");

    return 0;
}
