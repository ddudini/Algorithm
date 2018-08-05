//  boj_n7576
//  https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt;
vector<vector<int> > map;
vector<vector<int> > visited;
queue <pair<int, int> > Q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
    if(cnt == 0) return 0;
    
    int ans = 1;
    int x, y;
    while(!Q.empty()) {
        int qsize = Q.size();
        
        for(int i=0; i<qsize; i++){
            x = Q.front().second;
            y = Q.front().first;
            Q.pop();
            
            bool flag = false;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx <0 || ny < 0 || nx >= M || ny >= N) continue;
                if(map[ny][nx] == -1) continue;
//                if(visited[ny][nx] == 1) continue;
                if(map[ny][nx] == 0) {
                    map[ny][nx] = 1;
                    Q.push({ny, nx});
                    flag = true;
//                    visited[ny][nx] = 1;
                    cnt--;
                    if(cnt == 0) return ans;
                }
            }
        }
        
        ans++;

    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    cin >> M >> N;
    map.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M, 0));
    
    for(int i=0; i< N; i++){
        for(int j=0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) Q.push({i, j});
            else if(map[i][j] == 0) cnt++;
        }
    }
    cout << bfs();
    
    return 0;
}
