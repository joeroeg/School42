import random
import fractions
import csv
import os
import time

def generate_random_fraction(start, end):
    numerator = random.randint(start, end)
    denominator = random.randint(start, end)
    while numerator >= denominator or denominator == 0:
        numerator = random.randint(start, end)
        denominator = random.randint(start, end)
    return fractions.Fraction(numerator, denominator)

def generate_random_expression(start, end):
    num1 = generate_random_fraction(start, end)
    num2 = generate_random_fraction(start, end)
    operator = random.choice(['+', '-', '*', '/'])
    return (num1, num2, operator)

def calculate_expression(expression):
    num1, num2, operator = expression
    if operator == '+':
        return num1 + num2
    elif operator == '-':
        return num1 - num2
    elif operator == '*':
        return num1 * num2
    elif operator == '/':
        return num1 / num2

# Initialize counters for correct and incorrect answers
correct_count = 0
incorrect_count = 0

# Initialize a list to store expression data
expression_data = []

# Load previous results from a CSV file if available
csv_file = 'quiz_results.csv'
if os.path.exists(csv_file):
    with open(csv_file, 'r', newline='') as file:
        reader = csv.DictReader(file)
        expression_data = list(reader)

# Number of questions to ask
num_questions = 5


for _ in range(num_questions):
    expression = generate_random_expression(1, 10)
    result = calculate_expression(expression)

    print("Solve the following expression:")
    print('{} {} {} ='.format(expression[0], expression[2], expression[1]))
    
    # Record the starting time
    start_time = time.time()

    user_input = input("Your answer (in the form of a/b): ")
    user_fraction = fractions.Fraction(user_input)

    # Calculate the time taken for the answer
    end_time = time.time()
    time_taken = end_time - start_time

    if user_fraction == result:
        print("Correct! The real result is:", result)
        correct_count += 1
        correct = True
    else:
        print("Incorrect. The real result is:", result)
        incorrect_count += 1
        correct = False

    expression_result = {
        "expression": '{} {} {}'.format(expression[0], expression[2], expression[1]),
        "user_answer": user_fraction,
        "correct_answer": result,
        "correct": correct,
        "time_taken": time_taken  # Add the time taken to the result data
    }

    expression_data.append(expression_result)

# Save the combined results to the same CSV file
with open(csv_file, 'w', newline='') as file:
    fieldnames = ["expression", "user_answer", "correct_answer", "correct", "time_taken"]
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    writer.writeheader()
    writer.writerows(expression_data)

# Display the overall results
print("\nQuiz Results:")
print("Correct answers:", correct_count)
print("Incorrect answers:", incorrect_count)

# Display detailed information about each expression
print("\nExpression Details:")
for data in expression_data:
    print(f"Expression: {data['expression']}")
    print(f"User Answer: {data['user_answer']}")
    print(f"Correct Answer: {data['correct_answer']}")
    print(f"Correct: {'Yes' if data['correct'] else 'No'}\n")
