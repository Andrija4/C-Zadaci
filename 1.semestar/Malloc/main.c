#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    int* p;

    p = malloc(100*sizeof(int));

    if(p==NULL){
        printf("Nema dovoljno memorije");
        exit(EXIT_FAILURE);
    }
    for(k=0;k<100;k++){
        p[k]=rand() % 1000;
        printf("p[%d] = %3d \n", k, p[k]);
    }
    printf("p = %p\n", p);
    free(p);

    return 0;
}
