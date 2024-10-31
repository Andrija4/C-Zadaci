#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,zbir=0;
    printf("Unesite velicinu matrice: \n");
    scanf("%d", &n);

    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
            if(i+j<n-1)
                zbir = zbir + mat[i][j];
        }
    }
    printf("%d", zbir);
    return 0;
}
