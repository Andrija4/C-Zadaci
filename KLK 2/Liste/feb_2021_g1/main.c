#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int meni(){
    printf("Izaberite opciju:\n");
    printf("\t1:Ucitaj podatke:\n");
    printf("\t2:Ispisi podatke:\n");
    printf("\t3:Ispisi teretane sa spravama:\n");
    printf("\t4:Ispisi teretane u opstini:\n");
    printf("\t5:Izlaz:\n");

    int n;
    printf("Vas unos:");
    scanf("%d", &n);
    return n;
}

typedef struct teretana{
    char opstina[50];
    char naziv[50];
    int brojSprava;
    int brojSpravaK;
}teretana;

teretana* napraviTeretanu(char opstina[], char naziv[], int brojSprava, int brojSpravaK){
    teretana* t = (teretana*)malloc(sizeof(teretana));

    strcpy(t->opstina,opstina);
    strcpy(t->naziv,naziv);
    t->brojSprava=brojSprava;
    t->brojSpravaK=brojSpravaK;

    return t;
}

int porediTeretanu(teretana* t1, teretana* t2){
    return -(strcmp(t1->opstina,t2->opstina));
}

void ispisiTeretanu(teretana* t){
    printf("Opstina:%s, Teretana:%s, Broj sprava:%d, Broj sprava za kradio:%d\n",t->opstina,t->naziv,t->brojSprava,t->brojSpravaK);
}

void obrisiTeretanu(teretana* t){
    free(t);
}

typedef struct list{
    teretana* value;
    struct list* next;
}list;

list* napraviListu(char opstina[], char naziv[], int brojSprava, int brojSpravaK){
    list* e = (list*)malloc(sizeof(list));

    e->value = napraviTeretanu(opstina,naziv,brojSprava,brojSpravaK);
    e->next = NULL;
    return e;
}

list* dodajListu1(list* head, list* e){
    if(head->next==NULL){
        head->next = e;
        return head;
    }
    if(porediTeretanu(head->next->value,e->value)<0){
        dodajListu1(head->next,e);
        return head;
    }
    e->next = head->next;
    head->next = e;
    return head;
}

list* dodajListu(list* head,char opstina[], char naziv[], int brojSprava, int brojSpravaK){
    list* e = napraviListu(opstina,naziv,brojSprava,brojSpravaK);

    if(head==NULL)
        return e;
    if(porediTeretanu(head->value,e->value)>0){
        e->next=head;
        return e;
    }
    if(head->next==NULL){
        head->next = e;
        return head;
    }

    return dodajListu1(head,e);
}

void ispisiListu(list* head){
    for(list* e = head;e;e = e->next){
        ispisiTeretanu(e->value);
    }
}

void obrisiListu(list* head){
    if(head){
        obrisiListu(head->next);
        free(head);
    }
}

list* zad1(char* filename){
    FILE* fp = fopen(filename, "r");
    list* e = NULL;
    char line[50];

    while(fgets(line,50,fp)==line){
        char* opstina = strtok(line,"-");
        char* naziv = strtok(NULL,"-");
        int brojSprava = atoi(strtok(NULL,"-"));
        int brojSpravaK = atoi(strtok(NULL,"-"));

        e = dodajListu(e,opstina,naziv,brojSprava,brojSpravaK);
    }
    fclose(fp);
    return e;
}

void zad2(list* head){
    ispisiListu(head);
}

void zad3(list* head){
    int n;
    printf("Unesite broj: \n");
    scanf("%d", &n);

    for(list* e=head;e;e=e->next){
        if((e->value->brojSprava - e->value->brojSpravaK)>n){
            printf("%s-%s\n",e->value->opstina,e->value->naziv);
        }
    }
}

void zad4(list* head){
    char n[40];
    printf("Unesite sekvencu: \n");
    scanf("%s", &n);

    for(list* e=head;e;e=e->next){
        if(strstr(e->value->opstina,n)){
            printf("%s-%s\n",e->value->opstina,e->value->naziv);
        }
    }
}

void zad5(list* head){
    obrisiListu(head);
}

int main()
{
    list* e = NULL;
    int n;
    do{
        n = meni();
        switch(n){
            case 1:e = zad1("teretana.txt");break;
            case 2:zad2(e);break;
            case 3:zad3(e);break;
            case 4:zad4(e);break;
            case 5:zad5(e);break;
            default:printf("!Pogresan unos!\n");
        }

    }while(n!=5);

    return 0;
}
