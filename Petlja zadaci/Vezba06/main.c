#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b;
    printf("Unesite malo slovo:\n");
    scanf("%c", &a);
    b=a-32;
    if(a<97 || a>122)
        printf("Niste uneli malo slovo! \n");
    else
        printf("Veliko slovo je:%c", b);
    return 0;
}
