#include <stdio.h>

int OFFEN = 1;
int GESHCLOSSEN = 0;
void initArray(int** arr){
    for(int i =0; i<100;i++){
        arr[i]=&OFFEN;
    }
}

void toggleDoors(int** zellen, int intervall){
    for(int i = 0; i<100;i+=intervall){
        if(*zellen[i]){
            zellen[i] = &GESHCLOSSEN;
        }else{
            zellen[i] = &OFFEN;
        }
    }
}

int main(int argc, char const *argv[])
{
    int *zellen[100];
    initArray(zellen);
    for(int i = 2; i<100;i++){
        toggleDoors(zellen, i);
    }
    printf("Zellen die offen sind:\n");
    for(int i =0;i<100;i++){
        if(*zellen[i]){
            printf("%d ", i+1);
        }
    }
    printf("\n");
}