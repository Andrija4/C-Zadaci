#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int brojCifara(int n){
    int c=0;

    while(n!=0){
        n = n/10;
        c++;
    }
    return c;
}

int izvuciCifru(int n, int brojac){
    int cifra;

    cifra = (n / pow(10, brojac-1));
    cifra = cifra % 10;
    return cifra;
}

int main()
{
    int n, c;
    printf("Unesi cifru: \n");
    scanf("%d", &n);

    c = brojCifara(n);

    int matrix[c][c], brojac;

    //Unos cifara unutar matrice
    for(int i=0; i<c; i++){
        brojac = c;
        for(int j=0; j<c; j++){
            if(i%2==0){
                matrix[i][j] = izvuciCifru(n, brojac);
                brojac --;
            }
            else{
                matrix[i][j] = izvuciCifru(n, brojac) + 2;
                if(matrix[i][j] > 9)
                    matrix[i][j] -= 10;
                brojac --;
            }
        }
    }

    //Ispis matrice
    for(int i=0; i<c; i++){
        for(int j=0; j<c; j++){
            printf("%d \t", matrix[i][j]);
        }
    printf("\n");
    }

    return 0;
}
