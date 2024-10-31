#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
typedef struct{
    char ime[40];
    char prezime[40];
    int tezina;
}osoba;

void swap(osoba *a,osoba *b){
    osoba temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    //Citanje iz fajla
    FILE *fpI = fopen("osobe.txt","r");
    if(fpI==NULL){
        printf("Dosle je do greske! \n");
        fclose(fpI);
        return 0;
    }

    //Izvlacenje stringa iz konzole za naziv fajla
    char naziv[128];
    printf("Unesite naziv fajla u koji se upisuje rezultat: \n");
    fgets(naziv,128,stdin);

    //Otvaranje fajla u koji upisujemo
    FILE *fpO = fopen(naziv,"w");

    //Pravimo niz osoba
    osoba niz[MAX];
    int pos = 0;

    //Upacivanje svake osobe u niz
    while(!feof(fpI)){
        fscanf(fpI,"%s%s%d",niz[pos].ime,niz[pos].prezime,&niz[pos].tezina);
        if(niz[pos].ime!=0 && niz[pos].prezime!=0 && niz[pos].tezina!=0)
            pos++;
    }

    //Ukupan broj osoba
    int n = pos;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(niz[i].tezina>niz[j].tezina){
                swap(&niz[i],&niz[j]);
            }
        }
    }

    for(int i=0;i<n;i++)
        fprintf(fpO,"%s %s %d\n",niz[i].ime,niz[i].prezime,niz[i].tezina);

    return 0;
}
