#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int nadjiProst(int p){
    if(p<2)
        return 0;
    for(int i = 2; i*i<=p; i++){
        if(p%i==0)
            return 0;
    }
    return 1;
}
int jeKvadrat(int p){
    for(int i=0;i<=p;i++){
        if(i*i==p)
            return 1;
    }
    return 0;
}
int najbliziKvadrat(int p){
    int gornji = p;
    int donji = p;
    while(!jeKvadrat(donji))
        donji--;
    while(!jeKvadrat(gornji))
        gornji++;
    if(gornji-p<p-donji)
        return gornji;
    return donji;
}

int main()
{
    int n,m,min;

    printf("Unesite broj redova i kolona u matrici: \n");
    scanf("%d %d", &m, &n);
    int mat[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j]<1){
                printf("Matrica moze sadrzati brojeve samo > od 1!");
                return 0;
            }
        }
    }

    min = INT_MAX;

    printf("Matrica koju ste napravili:");
    for(int i=0; i<m; i++){
        printf("\n");
        for(int j=0; j<n; j++){
            printf("%d" , mat[i][j]);
            if(mat[i][j]<min && nadjiProst(mat[i][j])==1)
                min = mat[i][j];
        }
    }

    printf("\nMinimalna vrednost je: \n%d", min);
    printf("\nNajblizi kvadrat je: \n%d", najbliziKvadrat(min));

    return 0;
}
