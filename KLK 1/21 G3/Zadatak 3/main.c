#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Unesi n: \n");
    scanf("%d", &n);

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            if(i==j || i+j==n-1){
                putchar('^');
                continue;
            }
            else if(j%2!=0 && (i==0 || i==n-1) && j!=n-1){
                putchar('-');
                continue;
            }
            else if(j%2==0 && (i==0 || i==n-1) && j!=n-1 && j!=n-1){
                putchar('*');
                continue;
            }
            else if(j>i && j+i<=n-2){
                putchar('(');
                continue;
            }
            else if(j<i && j+i>=n){
                putchar(')');
                continue;
            }

            putchar(' ');

        }
        printf("\n");
    }

    return 0;
}
