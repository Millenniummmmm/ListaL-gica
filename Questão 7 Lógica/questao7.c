
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

void distribuir_negacao(char expressao[]) {
    char novaExpressao[256];
    int i, j = 0;
    int tam = strlen(expressao);

    for (i = 0; i < tam; i++) {
        if (expressao[i] == '!' && expressao[i+1] == '(') {
            i += 2; // Pula '!' e '('
            novaExpressao[j++] = '(';
            while (expressao[i] != ')' && expressao[i] != '\0') {
                if (expressao[i] == '&') {
                    novaExpressao[j++] = '|';
                } else if (expressao[i] == '|') {
                    novaExpressao[j++] = '&';
                } else if (expressao[i] == 'P' || expressao[i] == 'Q' || expressao[i] == 'R' || expressao[i] == 'S' || expressao[i] == 'T') {
                    novaExpressao[j++] = '!';
                    novaExpressao[j++] = expressao[i];
                } else {
                    novaExpressao[j++] = expressao[i];
                }
                i++;
            }
            novaExpressao[j++] = ')';
        } else {
            novaExpressao[j++] = expressao[i];
        }
    }
    novaExpressao[j] = '\0';
    strcpy(expressao, novaExpressao);
}

int analisar(char expressao[], bool p, bool q, bool r, bool s, bool t) {
    int i, resultado = 0;
    int tam = strlen(expressao);
    
    for (i = 0; i < tam; i++) {
        char caracter = expressao[i];
        
        if (caracter == '1')
            resultado = 1;
        else if (caracter == '0')
            resultado = 0;
        else if (caracter == 'P')
            resultado = p;
        else if (caracter == 'Q')
            resultado = q;
        else if (caracter == 'R')
            resultado = r;
        else if (caracter == 'S')
            resultado = s;
        else if (caracter == 'T')
            resultado = t;
        
        else if (caracter == '!') {
            i++;
            if (expressao[i] == 'P')
                resultado = !p;
            else if (expressao[i] == 'Q')
                resultado = !q;
            else if (expressao[i] == 'R')
                resultado = !r;
            else if (expressao[i] == 'S')
                resultado = !s;
            else if (expressao[i] == 'T')
                resultado = !t;
            else if (expressao[i] == '1')
                resultado = 0;
            else if (expressao[i] == '0')
                resultado = 1;
        }
        
        else if (caracter == '&') {
            resultado = resultado && analisar(expressao + i + 1, p, q, r, s, t);
            break;
        }
        else if (caracter == '|') {
            resultado = resultado || analisar(expressao + i + 1, p, q, r, s, t);
            break;
        }
        else if (caracter == '>') {
            resultado = (!resultado) || analisar(expressao + i + 1, p, q, r, s, t);
            break;
        }
        
        else if (caracter == '(') {
            int j = i + 1;
            int contParenteses = 1;
            while (j < tam && contParenteses > 0) {
                if (expressao[j] == '(') contParenteses++;
                if (expressao[j] == ')') contParenteses--;
                j++;
            }
            char subexpressao[256];
            strncpy(subexpressao, expressao + i + 1, j - i - 2);
            subexpressao[j - i - 2] = '\0';
            resultado = analisar(subexpressao, p, q, r, s, t);
            i = j - 1;
        }
    }
    return resultado;
}

// VERIFICAÇÃO
void avaliar_sentenca(char sentenca[]) {
    distribuir_negacao(sentenca);

    int i, resultado;
    int cont_true = 0, cont_false = 0;
    bool PTab[32] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
                     0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    bool QTab[32] = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 
                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    bool RTab[32] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 
                     0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    bool STab[32] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                     0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    bool TTab[32] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                     0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

    printf("\n\tJustifica -> Tabela Verdade:\n");
    printf("P\tQ\tR\tS\tT\t%s\n", sentenca);

    for (i = 0; i < 32; i++) {
        resultado = analisar(sentenca, PTab[i], QTab[i], RTab[i], STab[i], TTab[i]);
        
        // Exibe a tabela-verdade
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", PTab[i], QTab[i], RTab[i], STab[i], TTab[i], resultado);

        if (resultado) {
            cont_true++;
        } else {
            cont_false++;
        }
    }

    if (cont_true == 32) {
        printf("\nA sentença é uma Tautologia.\n");
    } else if (cont_false == 32) {
        printf("\nA sentença é uma Contradição.\n");
    } else {
        printf("\nA sentença é Satisfatível.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char sentenca[256];
    printf("\n\tColoque apenas 'P', 'Q', 'R', 'S' ou 'T', além dos operadores lógicos: '&', '!', '>', '|', '(', ')'\n");
    
    while (1) {
        printf("\n\tDigite sua sentença (ou '0' para sair): ");
        fgets(sentenca, 256, stdin);
        sentenca[strcspn(sentenca, "\n")] = 0;
        if (strcmp(sentenca, "0") == 0) break;
        
        avaliar_sentenca(sentenca);
    }
    
    return 0;
}
