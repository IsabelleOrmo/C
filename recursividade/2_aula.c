/*Fazer um programa com função recursiva que
retorna todos os primos de 1 até um número
fornecido.
*/
#include <stdio.h>
#include <stdbool.h>

bool EhPrimo(int n){
    for (int i = 2; i < n; i++)
    {
            if(n%i==0){
                return false;
            }
    }

    return true;
}

bool TemDivisor(int n, int div)
{
    if (div == 1)
    {
        return false;
    }
    if (n%div == 0)
    {
        return true;
    }
    else return TemDivisor(n, div-1);
}

bool EhPrimo2(int n)
{
    if (n <= 1) return true;

    return !TemDivisor(n, n-1);
}



int main(){

    int n;
    printf("Numero inteiro positivo: ");
    scanf("%d", &n);
    bool primo = EhPrimo2(n);
    if(primo == true){
        printf("\n %d eh um numero primo", n);
    } else {
        printf("\n %d nao eh primo", n);
    }

}