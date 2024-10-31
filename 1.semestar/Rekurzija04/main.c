#include <stdio.h>
#include <stdlib.h>

int dec2bin(n){

    int num=0;

    if(n==0)

        return num;

    if(n%2==0){
        num*= 10;
    }
    else{
        num*=10;
        num+=1;
        n=n-1;
    }

    return dec2bin(n/2);
}

int main()
{
    int broj, rez;
    printf("Unesite decimalan broj: \n");
    scanf("%d", &broj);

    rez=dec2bin(broj);
    printf("%d", rez);

    return 0;
}
//NEURADJEN
//IZBACUJE LOS IZLAZ
