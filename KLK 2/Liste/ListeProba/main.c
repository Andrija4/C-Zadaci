#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPerson{
    int age;
    struct sPerson *nextOsoba;
}Osoba;

Osoba *napraviOsobu(const int age){
    Osoba *novaOsoba = NULL;
    novaOsoba = malloc(sizeof(Osoba));
    if(novaOsoba != NULL){
        Osoba *nextOsoba = NULL;
        novaOsoba->age = age;
        printf("\nKreirana osoba na adresi: %p", novaOsoba);
    }
    else{
        printf("\nGreska u alokaciji memorije!!!\n");
    }
    return novaOsoba;
}

Osoba *ipisiListu(Osoba *lista){
    printf("Ispisivanje liste: \n");
    Osoba *t;
    t = lista;
    if(t==NULL){
        printf("Lista je prazna!\n");
    }
}

int main()
{
    Osoba *prvi = NULL;
    Osoba *zadnji = NULL;

    char odabir[64];
    int age;

    while(1){
        printf("\nUnesite odabir: \n");
        fgets(odabir,64,stdin);
        if(strcmp("q\n",odabir)==0){
            printf("\nIzlazak iz programa...");
            break;
        }
        else if(strcmp("print\n",odabir)==0){
            printf("\nIspisujem...");
        }
        else if(sscanf(odabir,"%d",&age)!=0){
            printf("\nDodajem...\n");
            if(prvi==NULL){
                prvi = napraviOsobu(age);
                if(prvi!=NULL){
                    zadnji = prvi;
                }
            }
            else{
                zadnji->nextOsoba=napraviOsobu(age);
                if(zadnji->nextOsoba!=NULL){
                    zadnji = zadnji->nextOsoba;
                }
            }
        }

    }
    return 0;
}
