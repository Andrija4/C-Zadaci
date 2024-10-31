#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    .......................................
    Prestupna godina

    Kada je broj deljiv sa 400
    ili
    Kada je deljiv sa 4 a nije sa 100
    .......................................
    */

    int g;

    printf("Unesi godinu: \n");
    scanf("%d", &g);

    if(g%400==0)
        printf("DA");

    else if(g%4==0 && g%100!=0)
        printf("DA");

    else
        printf("NE");


    return 0;
}
