//  boj_1525
//  https://www.acmicpc.net/problem/1525

#include <iostream>
#include <queue>
#include <set>

using namespace std;

long long ans;
long long input;
int shift[4] = {-12, 12, -4, 4};
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(){
    ans = 0;
    for(int i=1; i<9; i++){
        ans = (ans << 4) + i;
    }
    ans <<= 4;
    
    input = 0;
    for(int i=1; i <=9 ; i++){
        int temp;
        cin >> temp;
        input = (input << 4) + temp;
    }
    
    queue<long long> Q;
    set <long long> visited;
    int result = 0;
    
    Q.push(input);
    visited.insert(input);
    
    while( !Q.empty() ){
        int q_size = Q.size();
        
        for(int i=0; i<q_size; i++){
            long long cmap = Q.front();
            Q.pop();
            
            if (cmap == ans) {
                cout << result << endl;
                return 0;
            }
            
            int pos = 0;
            for(; cmap & (15LL << pos* 4) ; pos++);
            
            int r = pos/3;
            int c = pos%3;
            
            for(int j = 0; j<4; j++){
                int nr = r+dr[j];
                int nc = c+dc[j];
                
                if(nr<0 || nc < 0 || nr >=3 || nc >= 3) continue;
                
                long long temp = cmap & (15LL << (nr*3+nc)*4);
                long long next = cmap - temp;
                // 그리고 방향에 따라 temp를 시프트해 더하면 된다.
                if(shift[j] > 0) temp <<= shift[j];
                else temp >>= -shift[j];
                next += temp;
                
                if(visited.find(next) != visited.end()) continue;
                
                visited.insert(next);
                Q.push(next);
            }
        }
        result++;
    }
    

    
}
