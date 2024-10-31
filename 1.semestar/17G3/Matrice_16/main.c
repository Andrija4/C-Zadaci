#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j;
    int k, najmanji;
    printf("Unesi broj kolona: \n");
    scanf("%d", &n);

    printf("Unesi broj vrsta: \n");
    scanf("%d", &m);

    int matrix[n][m], matrix2[n][m];

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d \t", matrix[i][j]);
        }
    printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){

        najmanji = matrix[i][j];

        for(k=0; k<n; k++){
            if(matrix[k][j]<najmanji)
                najmanji = matrix[k][j];
        }

        for(k=0; k<m; k++){
            if(matrix[i][k]<najmanji)
                najmanji = matrix[i][k];
        }

        matrix2[i][j] = najmanji;
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d \t", matrix2[i][j]);
        }
    printf("\n");
    }

    return 0;
}

//IDE GASSSS
