#include <stdio.h>
#include <stdlib.h>

int rek(int a,int b){
    if(b==0)
        return 1;
    return a * rek(a,b-1);
}

int main()
{
    int a,b;
    printf("Unesite a i b: \n");
    scanf("%d %d", &a, &b);
    printf("rezutlat je: %d",rek(a,b));

    return 0;
}
