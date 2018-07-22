#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>
using namespace std;

typedef long TYPE;
/*
 4
 3
 5 4 3
 8
 2 2 2 2 2 2 2 4
 5
 4 1 3 3 1
 5
 9 10 9 10 10
 
 19
 54
 26
 */

int N;
vector <TYPE> arr;

TYPE solution(priority_queue <TYPE, vector<TYPE>, greater<TYPE> > Q) {
    TYPE ans = 0;
    
    while(Q.size() != 1){
        TYPE m1 = Q.top();
        Q.pop();
        TYPE m2 = Q.top();
        Q.pop();
        ans += m1 + m2;
        Q.push(m1+m2);
    }
    return ans;
};


int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++){
        cin >> N;
        arr = vector <TYPE> (N);
        
        priority_queue <TYPE, vector<TYPE>, greater<TYPE> > Q;
        for(int i =0; i < N ; i++){
            int temp;
            cin >> temp;
            arr[i] = temp;
            Q.push(temp);
        }
        
        TYPE ans = solution(Q);
        printf("#%d %ld\n", tc, ans);
        
    }
    
    
}

