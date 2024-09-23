/*Elabore um programa que leia um número inteiro
e construa os seguintes procedimentos
• int soma_digit(int a) – este procedimento irá somar os dígitos
desse número inteiro
• void Maior_Digit(int N, int *M) – este procedimento irá
determinar o maior dígito desse número inteiro
• Os resultados deverão ser impressos no programa principal*/

#include <stdio.h>

int soma_digit(int a){
    int somaD = 0;
    while (a > 0) {
        somaD += a % 10; 
        a=a/10;         
    }
    return somaD;
}

void Maior_Digit(int N, int *M){
    *M = 0; 
    int dgt;
    
    while (N > 0) {
        dgt = N % 10; 
        if (dgt > *M) {
            *M = dgt; 
        }
        N=N/10; 
    }
}

int main (){
    int a, maiorD;
    printf("Numero inteiro: ");
    scanf("%d", &a);

    int somaD = soma_digit(a);
    Maior_Digit(a, &maiorD);

    printf("\nA soma dos digitos de %d eh %d\n", a, somaD);
    printf("Seu maior digito eh %d\n", maiorD);


   return 0;
}