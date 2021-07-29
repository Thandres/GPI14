#include <stdio.h>

int main(int argc, char const *argv[])
{
    long num;
    int quersumme = 0;
    int ziffer;
    int groessteZifferGefunden = 0;
    printf("Gebe eine 12-stellige Zahl ein: ");
    scanf("%ld", &num);
    for (long maechtigkeit = 100000000000; maechtigkeit > 0; maechtigkeit/=10)
    { 
        ziffer = num / maechtigkeit;
        if(!groessteZifferGefunden && ziffer != 0){
            groessteZifferGefunden = 1;
        }
        if(groessteZifferGefunden){
            printf("%d\n", ziffer);
            quersumme += ziffer;
            num -= ziffer * maechtigkeit;
        }
    }
    printf("Quersumme: %d\n", quersumme);
    return 0;
}
