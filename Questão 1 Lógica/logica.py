def negacao(a, b):
    resultado = 0
    resultado2 = 0
    if not (a == b):         
        resultado += 1   
    if not (a < 2):    
        resultado2 += 1

    print("\n\tExemplo 1: ~(A = B).\n\tEntão a expressão é:", end="")
    if resultado == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

    print("\n\tExemplo 2: ~(A < 2).\n\tEntão a expressão é:", end="")
    if resultado2 == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

def disjuncao(a, b):
    resultado = 0
    resultado2 = 0
    if not (a or b) == 0:      
        resultado += 1   
    if (a or b) == 0:  
        resultado2 += 1

    print("\n\tExemplo 1: ~(A v B) = 0.\n\tEntão a expressão é:", end="")
    if resultado == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

    print("\n\tExemplo 2: (A v B) = 0.\n\tEntão a expressão é:", end="")
    if resultado2 == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

def conjuncao(a, b):
    resultado = 0
    resultado2 = 0
    if not (a and b):    
        resultado += 1   
    if a and b:  
        resultado2 += 1

    print("\n\tExemplo 1: ~(A ^ B) = 1.\n\tEntão a expressão é:", end="")
    if resultado == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

    print("\n\tExemplo 2: (A ^ B) = 1.\n\tEntão a expressão é:", end="")
    if resultado2 == 0:
        print(" Falsa (0).")
    else:
        print(" Verdadeira (1).")

def main():
    print("\n\t==============Trabalho de Lógica==============\n")
    print("\n\tPrimeira Questão:")
    print("\n\tDigite dois valores a e b, respectivamente.")
    a = int(input())
    b = int(input())

    print("\n\tExemplos de Negação:")
    negacao(a, b)
    
    print("\n\tExemplos de disjunção:")
    disjuncao(a, b)

    print("\n\tExemplos de conjunção:")
    conjuncao(a, b)

if __name__ == "__main__":
    main()
