#include<stdio.h>

int main(){

int a;

a=pov(242);
printf("%d", a);

return 0;
}

int pov(int broj){
int z,rezultat=1;
while(broj%10!=0)
{
    if(broj%10<5){
        z=broj%10;
        if(z%2==0){

            rezultat *= z;
        }
    }
    broj/=10;
}

return rezultat;
}
