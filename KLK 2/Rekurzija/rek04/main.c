#include <stdio.h>
#include <stdlib.h>

int dec2bin(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n%2==0)
        return dec2bin(n/2) * 10;
    else if(n%2!=0)
        return dec2bin(n/2) * 10 + 1;
}

int main()
{
    int n;
    printf("Unesite broj: \n");
    scanf("%d", &n);
    printf("Binarna vrednost je: %d", dec2bin(n));
    return 0;
}
