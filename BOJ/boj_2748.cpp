//  https://www.acmicpc.net/problem/2748
//  boj 2748

#include <iostream>
using namespace std;

long long fibo[91];
int N;

int main(){
    cin >> N;
    fibo[1] = 1;
    fibo[0] = 0;
    
    for(int i=2; i<= N; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[N];
}
