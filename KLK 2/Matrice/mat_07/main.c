#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Unesite kolone i redove matrice:\n");
    scanf("%d %d",&m,&n);

    int mat[m][n];
    putchar('\n');
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }

    putchar('\n');
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", mat[j][i]);
        }
        putchar('\n');
    }

    return 0;
}
