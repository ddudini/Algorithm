#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int  dp[1000001];
int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i=1; i<=N ; i++){
        cin >> arr[i];
        dp[i] = arr[i] > dp[i-1]+arr[i] ? arr[i] : dp[i-1]+arr[i];
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d", ans);
    
    
}
