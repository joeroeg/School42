main :: IO ()
main = loop 0
  where
    loop :: Int -> IO ()
    loop fahr
      | fahr <= 300 = do
          let celsius = (5.0 / 9.0) * fromIntegral (fahr - 32)
          putStrLn $ "°F: " ++ show fahr ++ "  °C: " ++ show celsius
          loop (fahr + 20)
      | otherwise = return ()
