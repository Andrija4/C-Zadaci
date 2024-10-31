#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, najmanji;

    printf("Unesi n: \n");
    scanf("%d", &n);

    printf("Unesi m: \n");
    scanf("%d", &m);

    int matrix[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            scanf("%d", &matrix[i][j]);

            if(i==0 && j==0)
                najmanji = matrix[i][j];

            if(najmanji > matrix[i][j])
                najmanji = matrix[i][j];

        }
    }

    printf("Najmanji element je: %d\n", najmanji);

    return 0;
}
