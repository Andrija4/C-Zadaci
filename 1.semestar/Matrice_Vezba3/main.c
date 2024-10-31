#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izvuciCifru(int n, int brojac){
    int rezultat;

    rezultat = (n / pow(10, brojac-1));
    rezultat = rezultat % 10;

    return rezultat;
}

int brojCifara(int n){
    int cifre = 0;

    while(n!= 0){
        n /= 10;
        cifre++;
    }
    return cifre;
}

int main()
{
    int n, brojac;
    printf("Unesi cifru: \n");
    scanf("%d", &n);

    int c = brojCifara(n);
    int matrix[c][c];

    brojac = c;
    for(int j=0; j<c; j++){
        matrix[0][j] = izvuciCifru(n, brojac);
        brojac--;
    }

    for(int i=1; i<c; i++){
        brojac = c;
        for(int j=0; j<c; j++){
            if(i%2==0){
                matrix[i][j] = matrix[i-1][j] - 3;
                brojac--;
            }
            else{
                matrix[i][j] = matrix[i-1][j] + 2;
                brojac--;
            }
            if(matrix[i][j]<0)
                matrix[i][j] = 10 + matrix[i][j];

            else if(matrix[i][j]>9)
                matrix[i][j] -= 10;
        }
    }

    for(int i=0; i<c; i++){
        for(int j=0; j<c; j++){
            printf("%d \t", matrix[i][j]);
        }
    printf("\n");
    }

    return 0;
}
//RESI
