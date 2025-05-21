#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

//Recursion (NO DP) way of solving problem
int cal_ways_rec(int n){
    if (n==0||n==1) return 0;
    else if (n==2) return 1;
    else if(n==3) return 2;
    else{
        return (cal_ways_rec(n-1)+cal_ways_rec(n-2));
    }   
}

//Calculate using memorization
int cal_ways_mem(int n, vector<long> &mem){
    if (n==0||n==1) return 0;
    else if (n==2) return 1;
    else if(n==3) return 2;
    else if (mem[n] != -1) return mem[n]; // If already calculated, return the stored value
    else {
        mem[n] = cal_ways_mem(n-1, mem) + cal_ways_mem(n-2, mem); // Calculate and store the value
        return mem[n];
    }   
}

//calculate using tabulation
int cal_ways_tab(int n){
    if (n==0||n==1) return 0;
    else if (n==2) return 1;
    else if (n==3) return 2;
    else{
        vector<long> mem(n+1);
        mem[0]=0;
        mem[1]=0;
        mem[2]=1;
        mem[3]=2;

        for(int i=4;i<=n;i++){
            mem[i] = mem[i-1] + mem[i-2];
        }
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
    
    int step = n;
    // 1. Calculate Using Recursion only (NO DP TECHNIQUES)
    // std::cout << "(Recursion)Ways to go to step " << step << " is " << cal_ways_rec(step) << std::endl;

    // 2. Calculate Using Memorization
    vector<long> mem(step+1,-1);
    // std::cout << "(Memorization)Ways to go to step " << step << " is " << cal_ways_mem(step,mem) << std::endl;

    // 3. Calculate Using Tabulation
    std::cout << "(Tabulation)Ways to go to step " << step << " is " << cal_ways_tab(step) << std::endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout<<"Time Taken:"<<duration.count()<<" Micro Seconds"<<endl;
    
    return 0;
}