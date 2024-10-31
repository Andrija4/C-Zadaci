#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    printf("Unesite broj redova i kolona matrice: \n");
    scanf("%d %d", &n, &m);
    putchar('\n');

    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Naprevljena matrica je: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k = j+1;k<m;k++){
                if(mat[j][i]>mat[k][i]){
                    int p = mat[j][i];
                    mat[j][i] = mat[k][i];
                    mat[k][i] = p;
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
