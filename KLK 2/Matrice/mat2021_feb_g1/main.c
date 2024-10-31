#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v,k;
    printf("Unesite broj vrsta i kolona: \n");
    scanf("%d %d",&v,&k);

    int mat[v][k];
    for(int i=0;i<v;i++){
        for(int j=0;j<k;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<k;j++){

        }
    putchar('\n');
    }
    return 0;
/*

1 2 3 5 3 1
5 4 8 4 2 7
7 5 7 3 1 5
8 1 1 2 2 4
3 6 2 7 5 1

*/
}
