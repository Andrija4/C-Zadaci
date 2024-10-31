#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=5;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0 || i==4)
                printf("<");
            else if(i==1 || i==3){
                if(j==0 || j==4)
                    printf("-");
                else
                    printf(">");
            }

            else{
                if(j==2)
                    printf("<");
                else
                    printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}
