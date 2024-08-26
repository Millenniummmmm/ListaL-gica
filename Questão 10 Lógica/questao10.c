#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 256
#define MAX_ATOM_LENGTH 100
#define MAX_SYMBOLS 12

typedef struct {
    char sentence[MAX_ATOM_LENGTH];
    char symbol;
} Proposition;

// Função para mapear proposições atômicas
char mapProposition(Proposition props[], int *count, char *proposition) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(props[i].sentence, proposition) == 0) {
            return props[i].symbol;
        }
    }
    if (*count < MAX_SYMBOLS) {
        props[*count].symbol = 'M' + *count;
        strcpy(props[*count].sentence, proposition);
        (*count)++;
        return props[*count - 1].symbol;
    }
    return '?';  // Erro: muitos símbolos
}

// Função para substituir conectivos lógicos e mapear proposições
void translateToLogic(char *input, char *output) {
    char *token;
    char proposition[MAX_ATOM_LENGTH] = "";
    char antecedent[MAX_ATOM_LENGTH] = "";
    char consequent[MAX_ATOM_LENGTH] = "";
    Proposition props[MAX_SYMBOLS] = {{ "", '\0' }};
    int propCount = 0;
    int inAntecedent = 0;  // Flag para saber se estamos no antecedente da implicação
    int expectingProposition = 1;  // Flag para saber se estamos esperando uma proposição

    // Iterar através dos tokens
    token = strtok(input, " ");
    while (token != NULL) {
        // Remover pontuações finais
        size_t len = strlen(token);
        if (ispunct(token[len - 1])) {
            token[len - 1] = '\0';
        }

        // Verificar conectivos lógicos
        if (strcmp(token, "e") == 0 || strcmp(token, "ou") == 0 || 
            strcmp(token, "se") == 0 || 
            (strcmp(token, "somente") == 0 && strcmp(strtok(NULL, " "), "se") == 0)) {

            // Adiciona a proposição anterior ao output
            if (strlen(proposition) > 0) {
                char mappedSymbol = mapProposition(props, &propCount, proposition);
                strcat(output, &mappedSymbol);
                proposition[0] = '\0';  // Limpa a proposição
                expectingProposition = 1;
            }

            // Verificar o conectivo e adicionar ao output
            if (strcmp(token, "e") == 0) {
                strcat(output, " ^ ");
            } else if (strcmp(token, "ou") == 0) {
                strcat(output, " v ");
            } else if (strcmp(token, "se") == 0) {
                
                if (strlen(proposition) > 0) {
                    strcat(antecedent, proposition);
                    proposition[0] = '\0'; 
                }
                inAntecedent = 1;  
                expectingProposition = 1;

            } else if (strcmp(token, "somente") == 0) {
                strcat(output, " = ");
            }
            expectingProposition = 1;

        } else if (strcmp(token, "não") == 0) {
            strcat(output, "!");  
            expectingProposition = 1;  

        } else if (strcmp(token, "então") == 0) {
         
            strcat(output, " > ");
            inAntecedent = 0;  
            expectingProposition = 1;

        } else {
            
            if (inAntecedent) {
                if (strlen(antecedent) > 0) {
                    strcat(antecedent, " ");
                }
                strcat(antecedent, token);
            } else if (strlen(proposition) > 0) {
                strcat(proposition, " ");
                strcat(proposition, token);
            } else {
                strcpy(proposition, token);
            }
            expectingProposition = 0;
        }

        token = strtok(NULL, " ");
    }

    if (strlen(proposition) > 0) {
        if (inAntecedent) {
            strcat(antecedent, " ");
            strcat(antecedent, proposition);
            strcat(output, antecedent);
        } else {
            char mappedSymbol = mapProposition(props, &propCount, proposition);
            strcat(output, &mappedSymbol);
        }
    }

    if (strlen(antecedent) > 0 && !inAntecedent) {
        char mappedSymbol = mapProposition(props, &propCount, antecedent);
        strcat(output, &mappedSymbol);
    }
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    char output[MAX_SENTENCE_LENGTH] = "";

    printf("Digite uma sentença em linguagem natural: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);


    input[strcspn(input, "\n")] = '\0';

    translateToLogic(input, output);

    printf("Sentença traduzida para lógica proposicional: %s\n", output);

    return 0;
}