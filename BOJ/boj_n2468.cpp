//  boj_n2468
//  https://www.acmicpc.net/problem/2468
/*
 5
 6 8 2 6 2
 3 2 3 4 6
 6 7 3 3 2
 7 2 5 3 6
 8 9 5 2 7
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, height;
vector < vector<int> > map;
vector<vector<bool> > visited;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int y, int x, int h){
    queue<pair<int, int> > Q;
    Q.push({y, x});
    visited[y][x] = true;
    while(!Q.empty()){
        int xx = Q.front().second;
        int yy = Q.front().first;
        Q.pop();
        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[ny][nx]) continue;
            if(map[ny][nx] <= h) continue;
            
            visited[ny][nx] = true;
            Q.push({ny, nx});
        }
    }
 
}

int solution(int h){
    int sum = 0;
    
    visited.assign(N, vector<bool>(N, false));
    
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            if(map[i][j] > h){
                dfs(i, j, h);
                sum++;
            }
        }
    }

    return sum;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    map.resize(N, vector<int>(N));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            height = max(map[i][j], height);
        }
    }
    
    int ans = 0;
    
    for(int i=0; i<= height; i++){
        ans = max(ans, solution(i));
    }
    
    cout << ans;
    
    return 0;
}
