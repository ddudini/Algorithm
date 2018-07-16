//
//  main.cpp
//  boj_n2178
//  https://www.acmicpc.net/problem/2178
//  Created by Sujin Han on 2018. 7. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//  bfs 이용하여 경로 찾기.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int map[100][100];
int visited[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    vector < vector <int> > dis (N, vector <int> (M, N*M+1));
    
    queue <pair <int, int> > Q;
    Q.push(make_pair(0, 0));
    
    dis[0][0] = 1;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        
        for(int i=0; i<4; i++){
            int nr = cur.first  + dx[i];
            int nc = cur.second + dy[i];
            
            if(nr<0 || nc < 0 || nr >= N || nc >= M) continue;
            if(visited[nr][nc] == 0 && map[nr][nc]==1){
                Q.push(make_pair(nr, nc));
                visited[nr][nc] = 1;
                
                if(dis[nr][nc] > 1 + dis[cur.first][cur.second])
                    dis[nr][nc] = 1 + dis[cur.first][cur.second];
            }
        }
        
    }

    cout << dis[N-1][M-1];
    
    
    return 0;
}
