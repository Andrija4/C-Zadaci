#include <stdio.h>
#include <stdlib.h>

double izracunajDesni(int i){
    double rezultat=1, f1=1, f2=1;

    for(int j=1;j<i;j++){
        rezultat = f1 + f2;
        f1=f2;
        f2=rezultat;
    }

    return rezultat;
}

double rek(int i, int n){
    double desni;
    char levi;

    desni = izracunajDesni(i);
    levi = 'a' + (n/2-i-1); // d(a-3) c(a-2) b(a-1) a(a-0)

    if(i == (n/2) || i > (n/2))
        levi = 'a' + (n-i-1);

    if(i==n-1)
        return levi;

    if(n%2==0){
        if(i%2==0)
            return levi + desni/rek(i+1, n);

        else
            return levi - desni/rek(i+1, n);
    }
    else{
        if(i%2!=0)
            return levi + desni/rek(i+1, n);

        else
            return levi - desni/rek(i+1, n);
    }


}

int main(){

    int n;
    scanf("%d", &n);

    printf("%lf", rek(0, n));
    return 0;
}
