#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Unesite velicinu kolone i reda matrice: \n");
    scanf("%d %d",&m,&n);
    int mat[m][n];
    int i=0,j=0,b=1,j_max = n,i_max = m,j_min = -1,i_min=0;
    while(b!=m*n+1){
        while(j<j_max){
            mat[i][j] = b;
            b++;
            j++;
        }

        j--; //!
        i++;
        j_max--;

        if(b==m*n+1)
            break;

        while(i<i_max){
            mat[i][j] = b;
            b++;
            i++;
        }
        i--;
        j--;
        i_max--;

        if(b==m*n+1)
            break;

        while(j>j_min){
            mat[i][j] = b;
            b++;
            j--;
        }
        j++; //!
        i--;
        j_min++;

        if(b==m*n+1)
            break;

        while(i>i_min){
            mat[i][j] = b;
            b++;
            i--;
        }
        i++;//!
        j++;
        i_min++;
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d \t", mat[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
