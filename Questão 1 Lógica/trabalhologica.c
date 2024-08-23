#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>



int negacao(int a, int b)
{
    int resultado = 0, resultado2 = 0;
    if(!(a == b)) //a == b --> 1  |a = 2; b = 3 --> 0         
        resultado++;   
    if(!(a < 2))    //a > 2 --> 1   |a <= 2 --> 0 
        resultado2++;

    printf("\n\tExemplo 1: ~(A = B).\n\tEntão a expressão é:");
    if(resultado == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");

    printf("\n\tExemplo 2: ~(A < 2).\n\tEntão a expressão é:");
    if(resultado2 == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");
    return 0;
}

int disjuncao(int a, int b)
{
    int resultado = 0, resultado2 = 0;
    if(!(a || b) == 0) //Se "a" ou "b" for diferente de 0, vai sair 1. 1 negado é 0, e 0 = 0.    
        resultado++;   
    if((a || b) == 0)  //Se "a" ou "b" for diferente de 0, vai sair 0. 0 = 1.
        resultado2++;

    printf("\n\tExemplo 1: ~(A v B) = 0.\n\tEntão a expressão é:");
    if(resultado == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");

    printf("\n\tExemplo 2: (A v B) = 0.\n\tEntão a expressão é:");
    if(resultado2 == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");
    return 0;
}

int conjuncao(int a, int b){
    int resultado = 0, resultado2 = 0;
    if(!(a && b) == 1) //Se "a" ou "b" for 0, vai sair 0. 0 negado é 1, e 1 = 1.    
        resultado++;   
    if((a && b) == 1)  //Se "a" e "b" for diferente de 0, vai sair 1. 1 = 1.
        resultado2++;

    printf("\n\tExemplo 1: ~(A ^ B) = 1.\n\tEntão a expressão é:");
    if(resultado == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");

    printf("\n\tExemplo 2: (A ^ B) = 1.\n\tEntão a expressão é:");
    if(resultado2 == 0)
        printf(" Falsa (0).\n");
    else
        printf(" Verdadeira (1).\n");
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    char sentenca[256];
    int a, b;
    printf("\n\t==============Trabalho de Lógica==============\n");
    printf("\n\tPrimeira Questão:");
    printf("\n\tDigite dois valores a e b, respectivamente.\n");
    scanf("%d%d", &a, &b);

    printf("\n\tExemplos de Negaçãco: ");
    negacao(a, b);
    
    printf("\n\tExemplos de disjunção: ");
    disjuncao(a, b);

    printf("\n\tExemplos de conjunção: ");
    conjuncao(a, b);
    

    fgets(sentenca, 256, stdin);
    sentenca[strcspn(sentenca, "\n")] = 0;  // para tirar a quebra de linha
    printf("%s\n", sentenca);
    return 0;
}




