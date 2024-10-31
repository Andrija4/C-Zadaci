#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
    char s[] = "123-456-356-234";
    char c, broji=0;
    int suma = 0, sume[100];

    for(int i=0; i<strlen(s); i++){
        c = s[i];
        if(c >= '0' && c<='9'){
            suma += (c - '0');
        }
        else if(c == '-'){
            sume[broji] = suma;
            broji++;
            printf("%d , %d ", suma, sume[broji]);
            suma = 0;
        }
    }

    printf("%d", suma);

    return 0;
}
