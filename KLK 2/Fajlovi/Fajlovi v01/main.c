#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char naziv[150];
    char string[150];
    char *token;

    printf("Unesite naziv fajla: \n");
    fgets(naziv,150,stdin);
    naziv[strlen(naziv)-1] = '\0';

    FILE *fp = fopen(naziv,"r");

    if(fp==NULL){
        printf("Ne postoji file!!\n");
        fclose(fp);
        return 0;
    }
    while(fgets(string,150,fp)==string){
        char ime[40];
        char prezime[40];
        int tezina;

/*
        token = strtok(string," ");
        strcpy(ime,token);
        token = strtok(NULL," ");
        strcpy(prezime,token);
        token = strtok(NULL," ");
        tezina = atoi(token);
*/
        //2. nacin
        fscanf(fp,"%s%s%d",ime,prezime,&tezina);

        printf("%s %s %d\n", ime, prezime, tezina);
    }
    fclose(fp);

    return 0;
}
