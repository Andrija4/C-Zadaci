#include <stdio.h>
#include <stdlib.h>

void iscrtajMatricu(int n, int k){
    if(k>0){
        for(int i=0; i<n;i++){
            printf("*");
        }
        printf("\n");
    }
    iscrtajMatricu(n,k-1);
}

int main()
{
    int n,k;
    printf("Unesite sirinu i duzinu matrice: \n");
    scanf("%d %d", &n, &k);
    iscrtajMatricu(n,k);

    return 0;
}
