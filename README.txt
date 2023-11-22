# SLOPPYSIM README
# Written by Evelyn Ellis

This C++ program simulates a multi-threaded environment where threads perform work according to specified parameters. The simulation
allows customization of the number of threads, sloppiness, work time, work iterations, and the option to run CPU-bound or I/O-bound 
tasks. Additionally, the program supports logging functionality to observe the global and local thread behavior.

# Usage
	The program accepts command-line arguments to customize the simulation. Default values are used if no arguments are provided.

# Parameters
	Number of Threads (numThreads): The number of threads participating in the simulation.
	Sloppiness (sloppiness): Determines when the global counter is updated based on thread-local counters.
	Work Time (workTime): The duration of each unit of work in milliseconds.
	Work Iterations (workIterations): The total number of work units each thread performs.
	CPU Bound (cpuBound): If set to "true," simulates CPU-bound tasks; otherwise, simulates I/O-bound tasks.
	Logging Enabled (doLogging): If set to "true," enables logging to observe the global and local thread behavior.

# Running Instructions:
	To run this program, you should call make and the file name:
		make ./sloppySim
	The commands must be in the following order:
		<N_Threads> <Sloppiness> <work_time> <work iterations> <CPU_BOUND> <Do_Logging>

# Testing
	To test this sloppySim, call the "make test" command. This will run 5 tests, meant to reflect those
	given in the sample output on Blackboard. Additionally, testing.txt is included in this repo to show the
	sample output I got on my end. 
