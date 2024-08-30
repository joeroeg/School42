import time
import random
import matplotlib.pyplot as plt

def find_duplicate_sort(numbers):
    """
    Find the duplicate number in a list of integers using sorting
    """
    numbers.sort()
    for i in range(len(numbers) - 1):
        if numbers[i] == numbers[i + 1]:
            return numbers[i]
    return None

def find_duplicate_set(numbers):
    """
    Find the duplicate number in a list of integers using a hash set
    """
    seen = list()
    for num in numbers:
        if num in seen:
            return num
        seen.append(num)
    return None

def find_duplicates_list(numbers):
    """
    Find the duplicate number in a list of integers using a list
    """
    seen = list()
    for num in numbers:
        if num in seen:
            return num
        seen.append(num)
    return None

def find_duplicates_tuple(numbers):
    """
    Find the duplicate number in a list of integers using a tuple
    """
    seen = tuple()
    for num in numbers:
        if num in seen:
            return num
        seen += (num,)

def find_duplicates_dict(numbers):
    """
    Find the duplicate number in a list of integers using a dictionary
    """
    num_dict = dict()
    for num in numbers:
        if num in num_dict:
            return num
        num_dict[num] = 1
    return None

def test_find_duplicate(input_sizes, execution_time, find_duplicate):
    """
    Test the find_duplicate function with different input sizes
    """
    for size in input_sizes:
        numbers = [random.randint(0, 1000) for _ in range(size)]
        start_time = time.perf_counter()
        find_duplicate(numbers)
        end_time = time.perf_counter()
        execution_time.append(end_time - start_time)

def main():
    input_sizes = [100, 1000, 10000, 100000]
    sort_execution_times = []
    set_execution_times = []
    list_execution_times = []
    dict_execution_times = []
    tuple_execution_times = []

    test_find_duplicate(input_sizes, sort_execution_times, find_duplicate_sort)
    test_find_duplicate(input_sizes, set_execution_times, find_duplicate_set)
    test_find_duplicate(input_sizes, list_execution_times, find_duplicates_list)
    test_find_duplicate(input_sizes, tuple_execution_times, find_duplicates_tuple)
    test_find_duplicate(input_sizes, dict_execution_times, find_duplicates_dict)



    plt.plot(input_sizes, sort_execution_times, label="Sort solution")
    plt.plot(input_sizes, set_execution_times, label="Set solution")
    plt.plot(input_sizes, list_execution_times, label="List solution")
    plt.plot(input_sizes, tuple_execution_times, label="Tuple solution")
    plt.plot(input_sizes, dict_execution_times, label="Dict solution")

    plt.xlabel("Input size")
    plt.ylabel("Execution time (seconds)")
    plt.yscale("log")  # Logarithmic scale for y-axis
    plt.legend()
    plt.show()

if __name__ == "__main__":
    main()
