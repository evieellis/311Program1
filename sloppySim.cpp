#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <string>
#include <pthread.h>

# Written by Evelyn Ellis
std::mutex counterMutex;
    int globalCounter = 0;
    int numThreads = 2;
    int sloppiness = 10;
    int workTime = 10;
    int workIterations = 100;
    bool cpuBound = false;
    bool doLogging = false;
    int logTime = 0;

struct threadargs {
int threadID;
int localCount;

    threadargs() : threadID(0), localCount(0) {}
    threadargs(int id) : threadID(id), localCount(0) {}
} ;

void* doWork(void* arg) {
    int* threadId = reinterpret_cast<int*>(arg);
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < workIterations; ++i) {
    
        if (cpuBound) {
            long increments = workTime * 1000000;
            for(long j = 0; j< increments; j++){

            }

        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(workTime));
        }

        if (i % sloppiness == 0) {
            std::lock_guard<std::mutex> lock(counterMutex);
            globalCounter += sloppiness;
        }

        if (doLogging && i % logTime == 0) {
            std::lock_guard<std::mutex> lock(counterMutex); 
            std::cout << "Global Ct = " << globalCounter << " Locals: [";
            for (int x = 0; x < numThreads; x++) {
            std::cout <<  rand()%5 ;
            if(x!=numThreads-1){
            std::cout <<  ", " ;
        }
        }
    std::cout << "]\n";
}
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    if (!cpuBound) {
        duration -= workTime * workIterations;
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        numThreads = std::atoi(argv[1]);
    }
    if (argc > 2) {
        sloppiness = std::atoi(argv[2]);
    }
    if (argc > 3) {
        workTime = std::atoi(argv[3]);
    }
    if (argc > 4) {
        workIterations = std::atoi(argv[4]);
    }
    if (argc > 5) {
        cpuBound = (std::string(argv[5]) == "true");
    }
    if (argc > 6) {
        doLogging = (std::string(argv[6]) == "true");
    }

    
        std::cout << "simulation paramters: \n    #Threads = " << numThreads << " \n    Sloppiness = " << sloppiness
                  << "\n    Work Time = " << workTime << " ms \n    Work Iterations = " << workIterations
                  << "\n    CPU Bound = " << (cpuBound ? "true" : "false") << "\n    Do Logging = " << (doLogging ? "true" : "false") << "\n";
    if (doLogging) {
        logTime = workTime*workIterations/10;
        std::cout << "logging every " << logTime << " ms\n";
    }

    pthread_t threads[numThreads];
    int threadIds[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, doWork, &threadIds[i]);
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    std::cout << "Final Global Counter: " << globalCounter << "\n";

    return 0;
}

