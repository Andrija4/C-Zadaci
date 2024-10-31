#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,n;

    printf("Unesite x: \n");
    scanf("%d", &x);
    printf("Unesite n: \n");
    scanf("%d", &n);

    for(int j = 0; j<(n*2)+(x-1)*2*n;j++){
        for(int i = 0; i<(n*2)+(x-1)*2*n;i++){
            if (j%2==0){

                if(i%2==0)
                    putchar('/');

                else
                    putchar('\\');

            }
            else{

                if(i%2==0)
                    putchar('\\');

                else
                    putchar('/');

            }

        }
        putchar('\n');
    }



    return 0;
}
