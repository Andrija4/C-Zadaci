#include <stdio.h>
#include <stdlib.h>

int main()
{

char ch;
int broj=0;

while((ch=getchar())!='/n'){
    if(ch>='0' && ch<='9'){
        broj=broj*10 + ch-'0';
    }
    else{
        while(broj!=0){
            printf("%c", ch);
            broj-=1;
        }

}
}
    return 0;
}
