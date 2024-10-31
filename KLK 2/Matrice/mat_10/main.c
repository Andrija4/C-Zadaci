#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Unesite dimenziju matrice: \n");
    scanf("%d", &n);

    int mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                mat[i][j]=2;
            else if(i<j)
                mat[i][j]=1;
            else
                mat[i][j]=3;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
