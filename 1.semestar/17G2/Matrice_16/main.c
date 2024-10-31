#include <stdio.h>
#include <stdlib.h>

int izvuciCifru(int n, int brojac){
    int rezultat;

    rezultat = n / pow(10, brojac-1);
    rezultat = rezultat % 10;

    return rezultat;
}

int brojCifara(int n){
    int cifra = 0;
    while(n != 0){
        n /= 10;
        cifra++;
    }
    return cifra;
}

int main()
{
    int n, c;
    printf("Unesi n: \n");
    scanf("%d", &n);

    c = brojCifara(n);
    int brojac = c;
    int matrix[c][c];

    for(int j = 0; j<c; j++){
        matrix[c-1][j] = izvuciCifru(n, brojac);
        brojac--;
    }

    for(int i = c-2; i>=0; i--){
        for(int j=0; j<c; j++){
            if(i%2==0){
                matrix[i][j] = matrix[i+1][j] + 1;
            }
            else{
                matrix[i][j] = matrix[i+1][j] + 2;
            }

            if(matrix[i][j] > 9)
                matrix[i][j] -= 10;
            else if(matrix[i][j]<0)
                matrix[i][j] = 10 - matrix[i][j];
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
