#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,h,m,s;
    printf("Unesi vreme u sekundama:\n");
    scanf("%d", &x);
    h=x/3600;
    x=x-h*3600;
    m=x/60;
    x=x-m*60;
    s=x;
    printf("%d h:%d m:%d s",h,m,s);
    return 0;
}
