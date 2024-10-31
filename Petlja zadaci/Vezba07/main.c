#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,c;
    int b;

    printf("Unesi neko slovo:\n");
    scanf("%c", &a);
    printf("Unesi broj kojim sabiras: \n");
    scanf("%d", &b);
    c=a+b;
    printf("Rezultat je:%c", c);

    return 0;
}
