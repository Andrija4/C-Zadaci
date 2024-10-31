#include <stdio.h>
#include <stdlib.h>

int main()
{
    float TK,TC;
    printf("Unesite temp u celzijusima: \n");
    scanf("%f",&TC);

    TK = TC + 273.15;
    printf("Temperatura u kelvinima je:  \n%.1f", TK);

    return 0;
}
