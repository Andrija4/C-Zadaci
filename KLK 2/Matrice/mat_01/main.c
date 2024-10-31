#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,min;

    printf("Unesite broj redova i kolona u matrici: \n");
    scanf("%d %d", &m, &n);
    int mat[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Matrica koju ste napravili:");
    min = mat[0][0];
    for(int i=0; i<m; i++){
        printf("\n");
        for(int j=0; j<n; j++){
            printf("%d" , mat[i][j]);
            if(mat[i][j]<min)
                min = mat[i][j];
        }
    }

    printf("\nMinimalna vrednost je: \n%d", min);

    return 0;
}
