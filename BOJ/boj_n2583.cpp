//
//  main.cpp
//  boj_n2583
//  https://www.acmicpc.net/problem/2583
//  Created by Sujin Han on 2018. 7. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int map[102][102];
int visited[102][102];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector <int> ans;

void dfs(int y, int x){
    ans[ans.size()-1]++;
    visited[y][x] = 1;
    for(int i=0; i< 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N|| ny >= M) continue;
        if(visited[ny][nx] == 0 && map[ny][nx] == 0)
            dfs(ny, nx);
    }

}

int main(int argc, const char * argv[]) {
    cin >> M >> N >> K;
    
    while(K--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=x1; i < x2; i++){
            for(int j=y1; j < y2; j++)
                map[j][i] = 1;
        }
    }
    
    for(int i=0; i< M; i++){
        for(int j=0 ; j < N ; j++){
            if(visited[i][j] == 0 && map[i][j] == 0) {
                ans.push_back(0);
                dfs(i, j);
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i=0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
