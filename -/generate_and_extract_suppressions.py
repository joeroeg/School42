import subprocess
import re
import os

def run_valgrind_and_generate_suppressions(executable, args, output_log):
    valgrind_command = [
        "valgrind",
        "--leak-check=full",
        "--show-leak-kinds=all",
        "--gen-suppressions=all",
        "--log-file={}".format(output_log)
    ] + [executable] + args

    result = subprocess.run(valgrind_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

def extract_suppressions(input_file, output_file):
    start_suppression_re = re.compile(r'^{')
    end_suppression_re = re.compile(r'^}')
    in_suppression = False

    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            if start_suppression_re.match(line):
                in_suppression = True
            if in_suppression:
                outfile.write(line)
            if end_suppression_re.match(line):
                in_suppression = False
                outfile.write("\n")

if __name__ == "__main__":
    executable_path = "./cub3D"
    executable_args = ["maps/invalid/invalid_extension.cux"]
    valgrind_log = "valgrind-out.txt"
    suppressions_file = "suppressions.supp"
    run_valgrind_and_generate_suppressions(executable_path, executable_args, valgrind_log)
    extract_suppressions(valgrind_log, suppressions_file)
    os.remove(valgrind_log)
