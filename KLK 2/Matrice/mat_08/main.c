#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Unesite kolone i redove matrice:\n");
    scanf("%d %d",&m,&n);

    int mat[m][n];
    int tr=1;
    for(int i=0;i<n;++i){
        if(i%2){
            for(int j=m-1;j>=0;--j){
                mat[j][i] = tr++;
            }
        }
        else{
            for(int j=0;j<m;++j){
                mat[j][i] = tr++;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
