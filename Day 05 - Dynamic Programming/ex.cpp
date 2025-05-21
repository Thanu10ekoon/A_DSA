#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fib(int in){
    if (in==0) return 0;
    else if (in==1) return 1;
    else return fib(in-1) + fib(in-2);
}

int main(int argc, char *argv[]) {

    //using argc, argv parameters so we dont have to compile again and again
    if(argc < 2){
        cout<<"Usage"<<argv[0]<<"<n>"<<endl;
        return 0;
    }
    int n = stoi(argv[1]);

    //Measuring Time taken to run a program

    //#include <chrono>
    //using namespace std::chrono;
    auto start = high_resolution_clock::now();
    
    int fibn = n;
    std::cout << "Fibonacci of " << n << " is " << fib(fibn) << std::endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout<<"Time Taken:"<<duration.count()<<" Micro Seconds"<<endl;
    
    return 0;
}