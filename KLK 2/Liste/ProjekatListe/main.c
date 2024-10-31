#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char ime[40];
    char prezime[40];
    char smer[2];
    int brojUpisa;
    int godinaUpisa;
    double poeniNaPrvom;
    double poeniNaDrugom;
    double poeniNaTrecem;
    double poeniUkupno;
    char mailPregledaca[40];
}student;

student* kreirajStudenta(char ime[],char prezime[],char smer[]
                         ,int brojUpisa,int godinaUpisa, double poeniNaPrvom,
                         double poeniNaDrugom, double poeniNaTrecem,
                         double poeniUkupno,char mailPregledaca[]){

    student* noviStudent = (student*)calloc(1,sizeof(student));

    strcpy(noviStudent->ime,ime);
    strcpy(noviStudent->prezime,prezime);
    strcpy(noviStudent->smer,smer);
    noviStudent->brojUpisa = brojUpisa;
    noviStudent->godinaUpisa = godinaUpisa;
    noviStudent->poeniNaPrvom = poeniNaPrvom;
    noviStudent->poeniNaDrugom = poeniNaDrugom;
    noviStudent->poeniNaTrecem = poeniNaTrecem;
    noviStudent->poeniUkupno = poeniUkupno;
    strcpy(noviStudent->mailPregledaca,mailPregledaca);

    return noviStudent;

}

void ispisiStudenta(student* stud){
    printf("Student:%s %s, Indeks:%d/%d %s, Broj poena: %f + %f + %f = %f, Pregledac:%s\n",stud->ime,stud->prezime,stud->brojUpisa
            ,stud->godinaUpisa,stud->smer,stud->poeniNaPrvom,stud->poeniNaDrugom,stud->poeniNaTrecem,stud->poeniUkupno,stud->mailPregledaca);
}

void obrisiStudenta(student* stud){
    free(stud);
}

int porediStudenta(student* s1,student* s2){

    double ubp = s1->poeniUkupno-s2->poeniUkupno;
    if(ubp)
        return -ubp;

    int smer = strcmp(s1->smer,s2->smer);
    if(smer)
        return -smer;

    int god = s1->godinaUpisa-s2->godinaUpisa;
    if(god)
        return god;

    return s1->brojUpisa-s2->brojUpisa;
}

int studentOpseg(student* stud, double min){
    return stud->poeniUkupno>min;
}

typedef struct list{
    student* value;
    struct list* next;
}list;

list* napraviListu(char ime[],char prezime[],char smer[]
                         ,int brojUpisa,int godinaUpisa, int poeniNaPrvom,
                         double poeniNaDrugom, double poeniNaTrecem,
                         double poeniUkupno,char mailPregledaca[]){

    list* e = (list*)malloc(sizeof(list));
    e->value = kreirajStudenta(ime,prezime,smer,brojUpisa,godinaUpisa,poeniNaPrvom,poeniNaDrugom,poeniNaDrugom,poeniUkupno,mailPregledaca);
    e->next = NULL;

    return e;
}

list* listaDodaj1(list* head,list* e){
    if(head->next==NULL){
        head->next = e;
        return head;
    }
    if(porediStudenta(head->next->value,e->value)<0){
        listaDodaj1(head->next,e);
        return head;
    }
    e->next = head->next;
    head->next = e;
    return head;
}

list* listaDodaj(list* head, char ime[],char prezime[],char smer[]
                         ,int brojUpisa,int godinaUpisa, int poeniNaPrvom,
                         double poeniNaDrugom, double poeniNaTrecem,
                         double poeniUkupno,char mailPregledaca[]){

    list* e = napraviListu(ime,prezime,smer,brojUpisa,godinaUpisa,poeniNaPrvom,poeniNaDrugom,poeniNaTrecem,poeniUkupno,mailPregledaca);
    if(head==NULL)
        return e;
    if(porediStudenta(head->value,e->value)>0){
        e->next = head;
        return e;
    }
    if(head->next==NULL){
        head->next = e;
        return head;
    }
    return listaDodaj1(head, e);

}

void ispisiListu(list* head){
    if(head){
        ispisiStudenta(head->value);
        ispisiListu(head->next);
    }
}

void obrisiListu(list* head){
    if(head){
        obrisiListu(head->next);
        free(head);
    }
}

int brojiListuIte(list* head, double min){
    int count = 0;
    for(list* e = head;e;e=e->next){
        count += studentOpseg(e->value,min);
    }
    return count;
}

int brojiListuRek(list* head, double min){
    if(head==NULL)
        return 0;
    return studentOpseg(head->value, min) + brojiListuRek(head->next,min);
}

typedef struct nastavnik{
    char mail[30];
    double sumaPrvog;
    double sumaDrugog;
    double sumaTreceg;
    double suma;
}nastavnik;

int porediStudenta2(list* head){
    return strcmp(head->value->mailPregledaca,head->next->value->mailPregledaca);
}

list* zad1(char* filename){

    FILE *fp = fopen(filename,"r");
    list* e = NULL;
    char line[200];

    while (fgets(line, sizeof line, fp)) {
        int len = strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = 0;
        char* smer = strtok(line, ",");
        int brojUpisa = atoi(strtok(NULL, ","));
        int godinaUpisa = atoi(strtok(NULL, ","));
        char* ime = strtok(NULL, ",");
        char* prezime = strtok(NULL, ",");
        double poeniNaPrvom = atof(strtok(NULL, ","));
        double poeniNaDrugom = atof(strtok(NULL, ","));
        double poeniNaTrecem = atof(strtok(NULL, ","));
        double poeniUkupno = atof(strtok(NULL, ","));
        char* mailPregledaca = strtok(NULL, ",");
        e = listaDodaj(e, ime, prezime, smer, brojUpisa, godinaUpisa, poeniNaPrvom, poeniNaDrugom,
                       poeniNaTrecem, poeniUkupno, mailPregledaca);
    }

    fclose(fp);
    return e;
}

void zad2(list* head){
    ispisiListu(head);
}

void zad3(list* head){
    int min;
    printf("Unesite min:\n");
    scanf("%d", &min);
    printf("Rekurzivno:%d\nIterativno:%d\n",brojiListuRek(head,min),brojiListuIte(head,min));
}

void zad4(){
}

void zad5(list* e){
    obrisiListu(e);
}

int menu(){
    printf("Izaberite jednu od opcija:\n");
    printf("\t1:Ucitavanje rezultata studenata iz fajla:\n");
    printf("\t2:Ispis rezultata studenata na konzulu:\n");
    printf("\t3:Prebrojavanje studenata sa vise poena:\n");
    printf("\t4:Ispis ocenjivaca:\n");
    printf("\t5:Brisanje podataka iz memorije i izlaz iz programa:\n");
    printf("\nVasa opcija: ");
    int n;
    scanf("%d", &n);
    return n;
}



int main()
{
    int n;
    list* e = NULL;
    do{
        n = menu();
        switch(n){
            case 1:e = zad1("rezultati.csv");break;
            case 2:zad2(e);break;
            case 3:zad3(e);break;
            case 4:zad4();break;
            case 5:zad5(e);break;
            default: printf("Uneli ste pogresnu opciju! \n");
        }
    }while(n!=5);

    return 0;
}
