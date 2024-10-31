#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float zbir,razlika,kolicnik;

    printf("Unesi a i b: \n");
    scanf("%d \n", &a);
    scanf("%d", &b);
    zbir = a + b ;
    razlika = a - b;
    kolicnik = a * b;

    printf("Zbir je: %f,\n Razlika je: %f \n Kolicnik je: %f\n",zbir ,razlika ,kolicnik);

    return 0;
}
