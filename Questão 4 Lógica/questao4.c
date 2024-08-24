#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int analisar(char expressao[], bool p, bool q, bool r) 
{
    int i, resultado = 0;
    int tamanho = strlen(expressao);
    
    for (i = 0; i < tamanho; i++) {
        char caracter = expressao[i];
        
        if(caracter == '1')
            resultado = 1;
        else if(caracter == '0')
            resultado = 0;
        else if(caracter == 'P')
            resultado = p;
        else if(caracter == 'Q')
            resultado = q;
        else if(caracter == 'R')
            resultado = r;

        else if(caracter == '!')
        {
            i++;
            if(expressao[i] == 'P')
                resultado = !p;
            else if(expressao[i] == 'Q')
                resultado = !q;
            else if(expressao[i] == 'R')
                resultado = !r;
            else if(expressao[i] == '1')
                resultado = 0;
            else if(expressao[i] == '0')
                resultado = 1;
        }
        
        // Operadores lógicos
        else if(caracter == '&')
        {
            resultado = resultado && analisar(expressao + i + 1, p, q, r);
            break;
        }
        else if(caracter == '|')
        {
            resultado = resultado || analisar(expressao + i + 1, p, q, r);
            break;
        }
        else if(caracter == '>')
        {
            resultado = (!resultado) || analisar(expressao + i + 1, p, q, r);
            break;
        }
        
        else if(caracter == '(')
        {
            int j = i + 1;
            int contParenteses = 1;
            while (j < tamanho && contParenteses > 0) {
                if(expressao[j] == '(') contParenteses++;
                if(expressao[j] == ')') contParenteses--;
                j++;
            }
            char subexpressao[256];
            strncpy(subexpressao, expressao + i + 1, j - i - 2);
            subexpressao[j - i - 2] = '\0';
            resultado = analisar(subexpressao, p, q, r);
            i = j - 1;
        }
    }
    return resultado;
}

int tabela(char sentenca[], char sentenca2[]) {
    int i, S1, S2;
    bool PTab[8] = {0, 0, 0, 0, 1, 1, 1, 1}; //tabela verdade 
    bool QTab[8] = {0, 0, 1, 1, 0, 0, 1, 1};
    bool RTab[8] = {0, 1, 0, 1, 0, 1, 0, 1};

    for(i = 0; i < 8; i++)
    {
        S1 = analisar(sentenca, PTab[i], QTab[i], RTab[i]);
        S2 = analisar(sentenca2, PTab[i], QTab[i], RTab[i]);
        if(S1 != S2)
            return 2;
    }
    return 1;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int resposta;
    char sentenca[256], sentenca2[256], nome[100];
    printf("=======================Equivalência Lógica=======================");
    printf("\n\tPara começar, digite seu nome:\n");
    fgets(nome, 100, stdin);
    printf("\n\tSaudações, %s\n", nome);
    printf("\n\tPara o funcionamento do programa, coloque apenas 'P', 'Q' ou 'R', além dos operadores lógicos: '&', '!', '>', '|', '(', ')'\n");
    printf("\n\tPara Verdadeiro digite 1 e para Falso digite 0.\n");
    while(1)
    {
        printf("\n\tDigite sua primeira sentença (ou '0' para sair do programa): ");
        fgets(sentenca, 256, stdin);
        sentenca[strcspn(sentenca, "\n")] = 0;
        if(strcmp(sentenca, "0") == 0) break;
        
        printf("\n\tDigite sua segunda sentença: ");
        fgets(sentenca2, 256, stdin);
        sentenca2[strcspn(sentenca2, "\n")] = 0;

        if((strcmp(sentenca, "!(P&Q)") == 0 && strcmp(sentenca2, "!P|!Q") == 0) || 
            (strcmp(sentenca, "!(P|Q)") == 0 && strcmp(sentenca2, "!P&!Q") == 0) || 
            (strcmp(sentenca2, "!(P&Q)") == 0 && strcmp(sentenca, "!P|!Q") == 0) || 
            (strcmp(sentenca2, "!(P|Q)") == 0 && strcmp(sentenca, "!P&!Q") == 0))
        {
            
            printf("\n\tSua primeira sentença: %s\n", sentenca);
            printf("\tSua segunda sentença: %s\n", sentenca2);
            printf("\n\tAs sentenças são logicamente equivalentes.\n");
        }
        else
        {
            resposta = tabela(sentenca, sentenca2);

            printf("\n\tSua primeira sentença: %s\n", sentenca);
            printf("\tSua segunda sentença: %s\n", sentenca2);

            if (resposta == 1)
                printf("\n\tAs sentenças são logicamente equivalentes.\n");
            else if (resposta == 2)
                printf("\n\tAs sentenças não são logicamente equivalentes.\n");
        }
    }
    
    return 0;
}
