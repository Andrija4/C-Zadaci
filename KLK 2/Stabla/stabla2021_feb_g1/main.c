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
    t->brojSprava = brojSprava;
    t->brojSpravaK = brojSpravaK;

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

typedef struct tree{
    teretana* value;
    struct tree* left;
    struct tree* right;
}tree;

tree* napraviTree(char opstina[], char naziv[], int brojSprava, int brojSpravaK){
    tree* t = (tree*)malloc(sizeof(tree));

    t->value = napraviTeretanu(opstina,naziv,brojSprava,brojSpravaK);
    t->left=NULL;
    t->right=NULL;

    return t;
}

tree* dodajTree(tree* root,char opstina[], char naziv[], int brojSprava, int brojSpravaK){
    tree* e = napraviTree(opstina,naziv,brojSprava,brojSpravaK);

    if(root==NULL)
        return e;
    if(porediTeretanu(root->value,e->value)>0){
        root->left = dodajTree(root->left,opstina,naziv,brojSprava,brojSpravaK);
    }
    else{
        root->right = dodajTree(root->right,opstina,naziv,brojSprava,brojSpravaK);
    }

    return root;
}

void ispisiTree(tree* root){
    if(root){
        ispisiTree(root->left);
        ispisiTeretanu(root->value);
        ispisiTree(root->right);
    }
}

void obrisiTree(tree* root){
    if(root){
        obrisiTree(root->left);
        obrisiTree(root->right);
        obrisiTeretanu(root->value);
        free(root);
    }
}

tree* zad1(char* filename){
    FILE* fp = fopen(filename,"r");
    tree* root = NULL;
    char linija[40];

    while(fgets(linija,40,fp)==linija){
        char* opstina = strtok(linija,"-");
        char* naziv = strtok(NULL,"-");
        int brojSprava = atoi(strtok(NULL,"-"));
        int brojSpravaK = atoi(strtok(NULL,"-"));
        root = dodajTree(root,opstina,naziv,brojSprava,brojSpravaK);
    }
    fclose(fp);
    return root;
}

void zad2(tree* root){
    ispisiTree(root);
}


void zad5(tree* root){
    obrisiTree(root);
}

int main()
{
    int n;
    tree* t = NULL;
    do{
        n = meni();
        switch(n){
            case 1:t=zad1("teretana.txt");break;
            case 2:zad2(t);break;
            case 3:zad3();break;
            case 4:zad4();break;
            case 5:zad5(t);break;
            default:printf("!Pogresan unos!\n");
        }

    }while(n!=5);

    return 0;
}
