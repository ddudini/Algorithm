// boj_13913
//  https://www.acmicpc.net/problem/13913
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
void find(int x){
    vector<int> visited(100001, -1);
    
    queue<int> q;
    q.push(x);
    visited[x] = x;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        
        if(cx == K){
            vector <int> path;
            while(cx != N){
                path.push_back(cx);
                cx = visited[cx];
            }
            
            cout << path.size() << endl << N<< " ";
            for(int i=path.size()-1 ; i >= 0; i--){
                cout << path[i] << " ";
            }
            cout << endl;
        }
        
        for(int i=-1; i<=3; i+=2){
            int nx = cx + i;
            if(i == 3) nx = 2*cx;
            if(nx < 0 || nx > 100000) continue;
            if(visited[nx] != -1) continue;
            visited[nx] = cx;
            q.push(nx);
        }
    }
}
    
int main() {
    cin >> N >> K;
    find(N);
}
