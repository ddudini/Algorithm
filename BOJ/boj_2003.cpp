// boj 2003
// https://www.acmicpc.net/problem/2003

#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    int arr[N];
    int ans = 0;
    int sidx = 0;
    int sum = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        
        sum += arr[i];
        
        while(sum > M) sum-=arr[sidx++];
        
        if(sum == M) ans++;
    }
    cout << ans;
    
}
