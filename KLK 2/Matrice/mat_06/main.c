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

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(mat[i][j]>mat[i][k]){
                    int p = mat[i][j];
                    mat[i][j] = mat[i][k];
                    mat[i][k] = p;
                }
            }
        }
    }

    putchar('\n');
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
