#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///ucitavanje
    int n;
    scanf("%d",&n);
    int matrix [n][n],matrix2 [n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }

    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix2 [i] [j]=0;
        }

    }
    ///ispis
    for( int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            printf("%d",matrix[i][j]);
        }
        printf("\n");

    }
    printf("\n");
    /// zadatak
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {

            if(i==j)
            {

                matrix2 [n-i-1][j]= matrix [i][j];
                matrix2 [i][j]= matrix [n-i-1][j];

            }
            if (matrix2[i][j] == 0){
                int najveci=0;

                if(matrix[i+1][j]%2==0 && matrix[i+1][j]>najveci && i>=0 && j>=0)
                    najveci = matrix[i+1][j];

                else if(matrix[i-1][j]%2==0 && matrix[i-1][j]>najveci && i>=0 && j>=0)
                    najveci = matrix[i-1][j];

                else if(matrix[i][j+1]%2==0 && matrix[i][j+1]>najveci && i>=0 && j>=0)
                    najveci = matrix[i][j+1];

                else if(matrix[i][j-1]%2==0 && matrix[i][j-1]>najveci && i>=0 && j>=0)
                    najveci = matrix[i][j-1];

                matrix2[i][j] = najveci;

            }

        }
    }




    ///ispis
    for( int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            printf("%d",matrix2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
