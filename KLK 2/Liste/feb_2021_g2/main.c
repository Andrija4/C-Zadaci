#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int meni(){
    int n;
    printf("Unesite opciju koju zelite:\n");
    printf("\t1:Ucitavanje artikla:\n");
    printf("\t2:Ispis svih artikla:\n");
    printf("\t3:Prikaz najeftinije radnje za artikle:\n");
    printf("\t4:Prikaz posebnih artikla iz radnji:\n");
    printf("\t5:Izlaz i brisanje liste:\n");
    scanf("%d", &n);
    return n;
}

typedef struct artikal{

    char naziv[50];
    char prodavnica[50];
    int cena;

}artikal;

artikal* napraviArtikal(char prodavnica[], char naziv[], int cena){
    artikal* noviArtikal = (artikal*)malloc(sizeof(artikal));

    strcpy(noviArtikal->prodavnica,prodavnica);
    strcpy(noviArtikal->naziv,naziv);
    noviArtikal->cena=cena;

    return noviArtikal;
}

int uporediArtikle(artikal* a1,artikal* a2){
    return -(strcmp(a1->naziv,a2->naziv));
}

void ispisiArtikal(artikal* a){
    printf("Prodavnica:%s,Artikal:%s,Cena:%d\n",a->prodavnica,a->naziv,a->cena);
}

void obrisiArtikal(artikal* a){
    free(a);
}

typedef struct list{
    artikal* value;
    struct list* next;
}list;

list* napraviListu(char prodavnica[], char naziv[], int cena){
    list* e = (list*)malloc(sizeof(list));

    e->value = napraviArtikal(prodavnica,naziv,cena);
    e->next = NULL;

    return e;
}

list* dodajListu1(list* head, list* e){
    if(head->next==NULL){
        head->next=e;
        return head;
    }
    if(uporediArtikle(head->next->value,e->value)<0){
        dodajListu1(head->next,e);
        return head;
    }
    e->next = head->next;
    head->next = e;
    return head;
}

list* dodajListu(list* head,char prodavnica[], char naziv[], int cena){
    list* e = napraviListu(prodavnica,naziv,cena);
    if(head==NULL)
        return e;
    if(uporediArtikle(head->value,e->value)>0){
        e->next=head;
        return e;
    }
    if(head->next==NULL){
        head->next=e;
        return head;
    }
    return dodajListu1(head, e);
}

void ispisiListu(list* head){
    if(head){
        ispisiListu(head->next);
        ispisiArtikal(head->value);
    }
}

void obrisiListu(list* head){
    if(head){
        obrisiListu(head->next);
        free(head);
    }
}

int porediRadnje(list* head, char* radnja){
    if(strcmp(head->value->prodavnica,radnja)==0)
        return 1;
    return 0;
}

void radnjaRek(list* head, char* radnja){
    if(head){
            if(porediRadnje(head,radnja))
                printf("%s\n", head->value->naziv);
            radnjaRek(head->next,radnja);
    }
    return 0;
}

void radnjaIte(list* head,char* radnja){
    for(list* e=head;e;e=e->next){
        if(porediRadnje(e,radnja))
            printf("%s\n\n", e->value->naziv);
    }
}

list* zad1(char* filename){
    FILE* fp = fopen(filename, "r");
    list* e = NULL;
    char line[200];
    while(fgets(line,200,fp)==line){
        char* prodavnica = strtok(line,",");
        char* naziv = strtok(NULL,",");
        int cena = atoi(strtok(NULL,","));
        e = dodajListu(e,prodavnica,naziv,cena);
    }
    fclose(fp);
    return e;
}

void zad2(list* head){
    ispisiListu(head);
}

int zad3(list* head){

    int flagM=0,flagI=0,stopM=0,stopI=0;
    int brojPonavljanja=0;
    int maxiU=0,ideaU=0;
    char unos[200];
    printf("Unesite artikle:\n");
    scanf("%s", &unos);

    if(unos==NULL){
        printf("Niste nista uneli!");
        return 0;
    }

    char* line = strtok(unos,",");
    while(line!=NULL){
        list* e = head;
        while(e){
            //Ukoluko naidjemo na taj artikal
            if(strcmp(e->value->naziv,line)==0){
                ispisiArtikal(e->value);
                brojPonavljanja++;
                if(strcmp(e->value->prodavnica,"maxi")==0){
                    maxiU+=e->value->cena;
                    flagM++;
                }
                else{
                    ideaU+=e->value->cena;
                    flagI++;
                }
            }
            e = e->next;
        }
        printf("broj ponavljanja:%d\n",brojPonavljanja);

        //Uslovi
        if(brojPonavljanja==1){
            if(stopM!=0 && flagM!=0){
                printf("Nije moguce pronaci sve artikle u jednoj prodavnici");
                return 0;
            }
            if(stopI!=0 && flagI!=0){
                printf("Nije moguce pronaci sve artikle u jednoj prodavnici");
                return 0;
            }
            if(flagI!=0)
                stopM++;
            else
                stopI++;
        }
        brojPonavljanja=0;
        flagI=0;flagM=0;
        line = strtok(NULL,",");
    }
    printf("Maxi ukupno:%d\nIdea ukupno:%d\n",maxiU,ideaU);
}

void zad4(list* head){
    char radnja[4];
    printf("Unesite radnju:");
    scanf("%s", &radnja);

    printf("REKURZIVNO:\n");
    radnjaRek(head,radnja);

    printf("\n ITERATIVNO:\n");
    radnjaIte(head,radnja);
}
void zad5(list* head){
    obrisiListu(head);
}

int main()
{
    int n;
    list* e = NULL;
    do{
        n = meni();
        switch(n){
            case 1:e = zad1("artikli.txt");break;
            case 2:zad2(e);break;
            case 3:zad3(e);break;
            case 4:zad4(e);break;
            case 5:zad5(e);break;
            default: printf("!Uneli ste pogresnu opciju!\n");
        }
    }
    while(n!=5);
    return 0;
}
