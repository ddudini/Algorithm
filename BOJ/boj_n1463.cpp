//https://www.acmicpc.net/problem/1463
//boj_n1463

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int ans[N+1];
    
    ans[N] = 0;
    for(int i=N-1; i > 0; i--){
        int idx3 = i*3;
        int idx2 = i*2;
        int idx1 = i+1;
        
        if(idx1 <= N) idx1 = ans[idx1] +1;
        if(idx2 <= N) idx2 = ans[idx2] +1;
        if(idx3 <= N) idx3 = ans[idx3] +1;
        
        ans[i] = min(idx1, idx2);
        ans[i] = min(ans[i], idx3);
//        cout << i << " " << ans[i] << endl;
        
    }
    cout << ans[1];
    return 0;
}
