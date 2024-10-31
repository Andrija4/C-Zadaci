#include <stdio.h>
#include <stdlib.h>
void matrica_zvezdica(int n, int m){
    int i;
    if(n==0)
        return ;

    for(i=0;i<m;i++){
        putchar('*');
    }
    putchar('\n');

    return matrica_zvezdica(n-1,m);
}

int main()
{
    int kol, red;
    printf("Unesite broj kol: \n");
    scanf("%d", &kol);

    printf("Unesite broj red: \n");
    scanf("%d", &red);

    matrica_zvezdica(kol, red);

    return 0;
}
// URADJEN
