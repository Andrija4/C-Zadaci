#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1,x2,y1,y2;
    float r;
    printf("Unesi x1: \n");
    scanf("%d", &x1);

    printf("Unesi x2: \n");
    scanf("%d", &x2);

    printf("Unesi y1: \n");
    scanf("%d", &y1);

    printf("Unesi y2: \n");
    scanf("%d", &y2);

    r=sqrt((pow((x2-x1),2)+pow((y2-y1),2)));
    printf("%.2f", r);
    return 0;
}
