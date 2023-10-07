import subprocess
import unittest


class TestWordCountProgram(unittest.TestCase):
    def test_spaces_single_space(self):
        input_text = "Hello world"
        expected_output = "0 2 11"
        self.run_and_assert(input_text, expected_output)
        
    # def run_and_assert(self, input_text, expected_output):
    #     subprocess.run(["gcc", "wordcount.c", "-o", "wordcount"])
    #     result = subprocess.run(["./wordcount"], input=input_text, stdout=subprocess.PIPE, text=True)
    #     self.assertEqual(result.stdout.strip(), expected_output)

if __name__ == "__main__":
    unittest.main()

    # def test_spaces_consecutive_spaces(self):
    #     input_text = "Hello   world"
    #     expected_output = "0 2 13"
    #     self.run_and_assert(input_text, expected_output)

    # def test_spaces_leading_spaces(self):
    #     input_text = "    Hello world"
    #     expected_output = "0 2 15"
    #     self.run_and_assert(input_text, expected_output)

    # def test_spaces_trailing_spaces(self):
    #     input_text = "Hello world   "
    #     expected_output = "0 2 15"
    #     self.run_and_assert(input_text, expected_output)

    # def test_spaces_mixed_spaces(self):
        # input_text = "Hello   world, how   are    you?"
        # expected_output = "0 7 35"
        # self.run_and_assert(input_text, expected_output)






#####################################################################################################################

# import subprocess
# import unittest

# class TestWordCountProgram(unittest.TestCase):
#     def test_wordcount(self):
#         # Compile the C program
#         subprocess.run(["gcc", "wordcount.c", "-o", "wordcount"])

#         # Run the compiled program with input and capture output
#         input_text = "Hello world\nThis is a test\n"
#         expected_output = "2 6 27"  # Corrected expected output for the given input
#         result = subprocess.run(["./wordcount"], input=input_text, stdout=subprocess.PIPE, text=True)

#         # Check if the program output matches the expected output
#         self.assertEqual(result.stdout.strip(), expected_output)

# if __name__ == "__main__":
#     unittest.main()


