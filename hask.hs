-- Nomes: Guilherme Utiama
--        Peter Brendel
--
-- Da uns ponto pra nois
-- Agradecimento especial: Kenny
-- Versao Brasileira: Herbert Richers

import System.IO
import Control.Applicative ((<$>))
import Data.Maybe (isJust, fromJust)
import Data.List
import Data.Function (on)

-- PROTECAO DIVINA INICIADA (NAO MEXER)
splitOn :: String -> char -> [String]
splitOn [] _ = []
splitOn string x = go string x [] ""
  where
      go [] y result temp = result
      go (x:xs) y result temp | x == '\n' = go xs y (result++[temp]) "" | otherwise = go xs y result (temp++[x])
-- PROTECAO DIVINA ENCERRADA

getNames :: [String] -> String -> Int -> [Int]
getNames [] _ _ = []
getNames (x:xs) name i
       | (isInfixOf name x) = [i] ++ (getNames xs name (i+1))
       | otherwise = getNames xs name (i+1)

use :: [Int] -> [Int]
use x
  | (length x == 2) = x
  | otherwise = []

main :: IO()
main = do
    d <- readFile "test.csv"
    let result =  splitOn d "\n"
    -- print result
    let segundam = take 2 (getNames result "segunda-matutino" 1)
    let segundav = take 2 (getNames result "segunda-vespertino" 1)

    let tercam = take 2 (getNames result "terca-matutino" 1)
    let tercav = take 2 (getNames result "terca-vespertino" 1)

    let quartam = take 2 (getNames result "quarta-matutino" 1)
    let quartav = take 2 (getNames result "quarta-vespertino" 1)

    let quintam = take 2 (getNames result "quinta-matutino" 1)
    let quintav = take 2 (getNames result "quinta-vespertino" 1)

    let sextam = take 2 (getNames result "sexta-matutino" 1)
    let sextav = take 2 (getNames result "sexta-vespertino" 1)

    writeFile "saida.txt" ("Segunda Matutino " ++ show (use segundam))
    appendFile "saida.txt" ("\nSegunda Vespertino " ++ show (use segundav))

    appendFile "saida.txt" ("\nTerca Matutino " ++ show (use tercam))
    appendFile "saida.txt" ("\nTerca Vespertino " ++ show (use tercav))

    appendFile "saida.txt" ("\nQuarta Matutino " ++ show (use quartam))
    appendFile "saida.txt" ("\nQuarta Vespertino " ++ show (use quartav))

    appendFile "saida.txt" ("\nQuinta Matutino " ++ show (use quintam))
    appendFile "saida.txt" ("\nQuinta Vespertino " ++ show (use quintav))

    appendFile "saida.txt" ("\nSexta Matutino " ++ show (use sextam))
    appendFile "saida.txt" ("\nSexta Vespertino " ++ show (use sextav))
