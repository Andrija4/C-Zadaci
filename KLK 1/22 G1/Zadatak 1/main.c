#include <stdio.h>
#include <stdlib.h>

int pom(int arg){

    int flag = 0;
    int n = arg/2;

    for(int j=1; j<arg;j++){

        for(int i=2;i<n;i++){   //U ovoj petlji gledamo da li je broj prost
            if(arg%i==0){
                arg = arg;
                flag = 1; //Ako nije prost flag je 1
                break;
            }
            else
                continue;
        }

        if(flag == 0){  //Izlazimo iz petlje jer je broj prost
            break;
        }

        if(flag == 1){  //Sta radimo sa brojem ako nije prost

            if(j%2!=0)
                arg = arg - j;
            else
                arg = arg + j;
            flag = 0;
        }
    }
    return arg;
}

int main()
{
    int a,b;
    printf("Unesite interval od-do: \n");
    scanf("%d%d",&a,&b);

    for(int k=a;k<=b;k++)
        printf("%d ", pom(k));

    return 0;
}
