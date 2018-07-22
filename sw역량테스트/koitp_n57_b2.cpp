#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 6
 5 2 2
 -37 33 0 -22 -32
 10 8 1
 30 4 -16 -50 -34 -18 -24 -17 19 -38
 15 10 4
 7 -41 -11 47 22 -6 -11 -31 -35 -17 -33 5 46 5 36
 20 17 2
 -23 16 33 7 0 7 18 39 35 14 -9 38 -19 -26 17 18 0 29 35 39
 25 13 11
 15 -30 42 38 25 2 28 16 34 37 31 15 -36 -31 40 27 -21 -20 50 -35 -31 -50 37 -45 4
 3 1 1
 -2 1 4
 */
int N, P, M;
int number[100000];
vector<int>ans;

void calculate(int pnum, int mnum, long int & sum) {
    if(pnum == P && mnum == M) return;
    
    if(pnum < P){
        sum += number[N-1-pnum];
        pnum++;
    }
    if(mnum < M){
        sum -= number[1+mnum];
        mnum++;
    }
    
    calculate(pnum, mnum, sum);
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++){
        cin >> N >> P >> M;
        for(int i=0; i< N; i++) cin >> number[i];
        long int c = number[0];
        sort(number+1, number+N);
        calculate(0, 0, c);
        printf("#%d %ld\n", tc, c);
    }
}
