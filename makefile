# Evelyn Ellis
# created 11/22/23

#compiles sloppySim.cpp, creates sloppSim executable
make: sloppySim.cpp
	g++ -std=c++11 -pthread sloppySim.cpp -o sloppySim
# tests sloppySim
test: sloppySim
	./test_script.sh
#removes sloppySim executable
clean:
	rm -f sloppySim