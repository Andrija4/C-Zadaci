#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    a=test(125,2);
    printf("%d", a);

    return 0;
}

int test(int n, int t){
    int z, mnozenje, m, g=n;
    while(g%10!=0){
        z=g%10;
        if(z==t){
            m=1;
            break;
        }
        g/=10;
    }
    if(m==1){
        mnozenje = n*t;
        return mnozenje;
    }
    else
        return 0;
}
