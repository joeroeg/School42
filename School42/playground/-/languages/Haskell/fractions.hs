import System.Random

randomFraction :: IO Float
randomFraction = do
    randomValue <- randomRIO (0, 1)
    return randomValue

main :: IO ()
main = do
    fraction <- randomFraction
    putStrLn $ "Random fraction: " ++ show fraction
