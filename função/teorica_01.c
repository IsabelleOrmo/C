
#include <stdio.h>

int verificaNum (int num){
    int verifica;
    if(num%2==0){
        verifica = 1;
    } else {
        verifica = 0;
    }
    return verifica;
}

int main (){
    int num;
    printf("Número: ");
    scanf("%d", &num);
    printf("Par = 1, Impar = 0 \n %d", verificaNum(num));
}