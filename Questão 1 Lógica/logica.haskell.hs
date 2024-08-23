import System.IO (hSetBuffering, stdout, BufferMode(NoBuffering))

-- Função de negação
negacao :: Int -> Int -> IO ()
negacao a b = do
    let resultado = if not (a == b) then 1 else 0
    let resultado2 = if not (a < 2) then 1 else 0

    putStrLn "\n\tExemplo 1: ~(A = B)."
    putStr "\tEntão a expressão é:"
    if resultado == 0
        then putStrLn " Falsa (0)."
        else putStrLn " Verdadeira (1)."

    putStrLn "\n\tExemplo 2: ~(A < 2)."
    putStr "\tEntão a expressão é:"
    if resultado2 == 0
        then putStrLn " Falsa (0)."
        else putStrLn " Verdadeira (1)."

-- Função de disjunção
disjuncao :: Int -> Int -> IO ()
disjuncao a b = do
    let resultado = if not (a /= 0 || b /= 0) then 0 else 1
    let resultado2 = if (a /= 0 || b /= 0) then 0 else 1

    putStrLn "\n\tExemplo 1: ~(A v B)."
    putStr "\tEntão a expressão é:"
    if resultado == 1
        then putStrLn " Verdadeira (1)."
        else putStrLn " Falsa (0)."

    putStrLn "\n\tExemplo 2: (A v B)."
    putStr "\tEntão a expressão é:"
    if resultado2 == 1
        then putStrLn " Verdadeira (1)."
        else putStrLn " Falsa (0)."

-- Função de conjunção
conjuncao :: Int -> Int -> IO ()
conjuncao a b = do
    let resultado = if not (a /= 0 && b /= 0) then 1 else 0
    let resultado2 = if (a /= 0 && b /= 0) then 1 else 0

    putStrLn "\n\tExemplo 1: ~(A ^ B) = 1."
    putStr "\tEntão a expressão é:"
    if resultado == 0
        then putStrLn " Falsa (0)."
        else putStrLn " Verdadeira (1)."

    putStrLn "\n\tExemplo 2: (A ^ B) = 1."
    putStr "\tEntão a expressão é:"
    if resultado2 == 0
        then putStrLn " Falsa (0)."
        else putStrLn " Verdadeira (1)."

-- Função principal
main :: IO ()
main = do
    hSetBuffering stdout NoBuffering -- Para garantir que o buffer seja limpo após cada putStr
    putStrLn "\n\t==============Trabalho de Lógica==============\n"
    putStrLn "\n\tPrimeira Questão:"
    putStrLn "\n\tDigite dois valores a e b, respectivamente."
    
    putStr "a: "
    a <- readLn
    putStr "b: "
    b <- readLn

    putStrLn "\n\tExemplos de Negação: "
    negacao a b

    putStrLn "\n\tExemplos de Disjunção: "
    disjuncao a b

    putStrLn "\n\tExemplos de Conjunção: "
    conjuncao a b