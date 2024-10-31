#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    a=funk(5321);
    printf("%d", a);
    return 0;
}

int funk(int broj){

int obrn=0,n=broj,rezultat=0;

while(n%10!=0){
    obrn*=10;
    obrn=obrn+(n%10);
    n/=10;
}

if(obrn<broj){
        n=broj;
    while(n%10!=0){
        rezultat=rezultat+(n%10);
        n/=10;
    }
return rezultat;
}
else
    return 0;

}
