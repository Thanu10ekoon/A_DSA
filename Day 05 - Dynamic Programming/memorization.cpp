#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int fib(int in){
    if (in==0) return 0;
    else if (in==1) return 1;
    else return fib(in-1) + fib(in-2);
}

//For memorization of previously calculated fibonacci numbers so we don't have to calculate them again and again from beginning
//This functions checks whether calculating fib number is already in vector called mem or not
//If it is already in vector, it returns the value from vector instead of calculating it again and again
//If it is not in vector, it calculates the value and stores it in vector for future use
int fib_mem(int n, vector<long> &mem){
    if (n==0) return 0;
    else if (n==1) return 1;
    else if (mem[n] != -1) return mem[n]; // If already calculated, return the stored value
    else {
        mem[n] = fib_mem(n-1, mem) + fib_mem(n-2, mem); // Calculate and store the value
        return mem[n];
    }   
}

int main(int argc, char *argv[]) {

    if(argc < 2){
        cout<<"Usage"<<argv[0]<<"<n>"<<endl;
        return 0;
    }
    int n = stoi(argv[1]);

    auto start = high_resolution_clock::now();
    
    int fibn = n;

    //intialized vector(array) with n size with all -1 values
    vector<long> mem(n+1,-1);
    std::cout << "Fibonacci of " << n << " is " << fib_mem(fibn,mem) << std::endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout<<"Time Taken:"<<duration.count()<<" Micro Seconds"<<endl;
    
    return 0;
}