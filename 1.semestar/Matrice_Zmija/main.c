#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ,m ,i ,j;
    printf("Unesi n: \n");
    scanf("%d", &n);

    printf("Unesi m: \n");
    scanf("%d", &m);

    int matrix[n][m];

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }


    for(i=0; i<n; i++){

        if(i%2==0){
            for(j=0; j<m; j++)
                printf("%d \t", matrix[i][j]);
        }
        else{
            for(j=m-1; j>=0; j--)
                printf("%d \t", matrix[i][j]);
        }
    printf("\n");
    }

    return 0;
}
//RESI
