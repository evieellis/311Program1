import subprocess
import time

# Written by Evelyn Ellis

# this script provides a convenient way to automate the execution of shell commands, gather information 
# about their outputs and errors, and record the execution time
def run_test(command):
    start_time = time.time()
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    out, err = process.communicate()
    end_time = time.time()
    return out.decode(), err.decode(), end_time - start_time

tests = [
    "./test_script.sh",
]

results = []

for test in tests:
    print(f"Running test: {test}")
    output, error, execution_time = run_test(test)
    print(f"Output:\n{output}")
    print(f"Error:\n{error}")
    print(f"Execution Time: {execution_time} seconds")
    print("--------------------------------------------------------")

    # collect results
    results.append({
        "test_command": test,
        "output": output,
        "error": error,
        "execution_time": execution_time
    })

# process & analyze results
for result in results:
    # example: print test command and execution time
    print(f"Test Command: {result['test_command']}")
    print(f"Execution Time: {result['execution_time']} seconds")
    print("--------------------------------------------------------")