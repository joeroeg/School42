-- Functional approach to calculate rectangular area in Haskell. Haskell comments start with --.

calculateRectangularArea :: Float -> Float -> Float -- This line declares a function named calculateRectangularArea. The :: symbol is used to specify the type signature of the function. It states that the function takes two Float arguments and returns a Float, representing the rectangular area.
calculateRectangularArea length width = length * width -- This line defines the body of the calculateRectangularArea function. It uses pattern matching to extract the values of length and width from the function arguments. The function body simply multiplies length and width to calculate the area of the rectangle.

-- Example usage
main :: IO () -- This line defines the main function, which is the entry point of the Haskell program. The :: symbol specifies the type signature of main, stating that it returns an IO (), which means it performs input/output actions. The IO monad allows side effects like reading from the console or writing to it.
main = do -- This line starts the do block, which allows us to sequence multiple IO actions. In Haskell, each line in a do block performs an IO action, and the block is terminated with an indentation.
    let length = 5.0 -- These lines use the let keyword to create local bindings within the do block. We define length and width variables with values 5.0 and 3.0, respectively. Then, we calculate the area using the calculateRectangularArea function by passing length and width as arguments.
        width = 3.0
        area = calculateRectangularArea length width
    putStrLn ("Rectangular area: " ++ show area) -- This line uses the putStrLn function from the IO module to print a string to the console. We concatenate the string "Rectangular area: " with the computed area value using the ++ operator. The show function converts the area value to a string, allowing it to be concatenated with the rest of the output.
