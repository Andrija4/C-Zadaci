#include <stdio.h>
#include <stdlib.h>

int zbirCifara(int a){
    if(a==0)
        return 0;
    else if(a < 0)
        return -zbirCifara(-a);
    return zbirCifara(a/10)+a%10;
}

int main()
{
    int a;
    printf("Unesite broj: \n");
    scanf("%d", &a);
    printf("%d", zbirCifara(a));
    return 0;
}
