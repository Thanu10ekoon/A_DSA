#include <iostream>

int fib(int in){
    if (in==0) return 0;
    else if (in==1) return 1;
    else return fib(in-1) + fib(in-2);
}

int main() {
    int fibn = 5;
    std::cout << "Fibonacci of " << fibn << " is " << fib(fibn) << std::endl;
    return 0;
}