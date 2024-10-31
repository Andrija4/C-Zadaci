#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50];
    int i=0, flag = 0, rez=1, broj=1;
    printf("Unesite sekvencu: ");
    scanf("%s", &s);

        while(s[i] != '\0'){

            if(s[i] == '['){
                flag = 1;
                putchar('[');
                i++;
                continue;
            }
            else if(s[i] == ']'){
                //printf("%d \n", rez);
                putchar(rez + '0');
                putchar(']');
                rez = 1; //vracamo rezultat na jedan da bi u sledecoj flag petlji mogli dobiti tacan rezultat
                flag = 0;
                i++;
                continue;
            }
            if(flag == 1){
                //sve dok je sledeci char isti racunamo sumu
                if(s[i] == s[i+1]){
                    broj++;
                    i++;
                    continue;
                }
                //Kada sledeci char nije isti mnozimo broj cifara sa rezultatom
                else{
                    rez = rez * broj;
                    broj = 1; //vracamo broj cifara istih ch na jedan
                    i++;
                    continue;
                }
            }
            putchar(s[i]); //ubacujemo karakter iz jednog stringa u drugi ako flag != 1

            i++;
        }
        putchar('\0');

    return 0;
}//mrk
