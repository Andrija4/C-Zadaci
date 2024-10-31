#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch,znak;
    int broj=0,rez1,rez2,rez=0;


    while((ch = getchar()) != '\n' && ch != EOF){

        if(ch>='0' && ch<='9'){

            broj = broj*10 + (ch-'0');
            printf("broj: \n%d \n", broj);

        }
        else if(ch == '+'){

            rez = rez + broj;
            printf("Konacan broj: \n%d \n", broj);
            printf("Rezultat: \n %d \n", rez);
            broj = 0;

        }
        else if(ch == '-'){

            rez = rez - broj;
            broj = 0;
        }
        else if(ch == '<' || ch == '>' || ch == '='){
            rez = rez + broj;
            printf("Konacan broj: \n%d \n", broj);
            printf("Rezultat: \n %d \n", rez);
            znak = ch;
            rez1 = rez;
            rez = 0;
            broj = 0;
        }
        else{
            printf("Pogresan unos! \n");
            break;
        }

    }
    rez = rez + broj;
    printf("Konacan broj: \n%d \n", broj);
    printf("Rezultat: \n %d \n", rez);
    rez2 = rez;
    if(znak == '<'){
        if(rez1 < rez2)
            printf("DA");
        else printf("NE");
    }

    else if(znak == '>'){
        if(rez1 > rez2)
            printf("DA");
        else printf("NE");
    }

    else if(znak == '='){
        if(rez1 = rez2)
            printf("DA");
        else printf("NE");
    }

    return 0;
}
