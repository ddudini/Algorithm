#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

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
vector <int> arr;

long int solution2(priority_queue <int, vector<int>, greater<int> > Q) {
    int ans = 0;
    while(Q.size() != 1){
        int m1 = Q.top();
        Q.pop();
        int m2 = Q.top();
        Q.pop();
        ans += m1 + m2;
        Q.push(m1+m2);
    }
    return ans;
};

long int solution(){
    long int sum = 0;
    
    vector <int> cal;
    while(arr.size() != 1){
        
        sort(arr.begin(), arr.end());
        arr.push_back(0);
        cal = vector<int>(0);
        cal.push_back ( arr[0] + arr[1] );
        sum += cal[0];
        
        int cidx = 0;
        
        for(int i=2 ; i < arr.size()-1 ; i++){
            if(cal[cidx] + arr[i] < arr[i] + arr[i+1]){
                cal[cidx] = cal[cidx] + arr[i];
                sum += cal[cidx];
            }
            else {
                cal.push_back( arr[i] + arr[i+1] ); cidx++;
                if(i != arr.size()-2) sum += cal[cidx];
                i+=1;
            }
        }
              
        arr = cal;
        
    }
    return sum;
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++){
        cin >> N;
        arr = vector <int> (N);
        
        priority_queue <int, vector<int>, greater<int> > Q;
        for(int i =0; i < N ; i++){
            int temp;
            cin >> temp;
            arr[i] = temp;
            Q.push(temp);
        }
        
        long int ans = solution2(Q);
        printf("#%d %ld\n", tc, ans);
        
    }
    
    
}

