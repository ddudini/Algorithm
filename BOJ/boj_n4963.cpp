//
//  main.cpp
//  boj_n4963
//  https://www.acmicpc.net/problem/4963
//  Created by Sujin Han on 2018. 7. 18..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int width, height;
int map[50][50];
int visited[50][50];
int sum;
int dx[8] = {0,0,1,-1, 1, 1, -1, -1};
int dy[8] = {1,-1,0,0, 1, -1, -1, 1};

void bfs(int c, int r){
    queue <pair <int, int> > Q;
    
    Q.push({c, r});
    visited[c][r] = 1;
    
    while(!Q.empty()){
        int cn = Q.front().first;
        int rn = Q.front().second;
        Q.pop();
        
        for(int i=0; i<8; i++){
            int next_c = cn + dy[i];
            int next_r = rn + dx[i];
            if(next_c < 0 || next_r < 0 || next_r >=width || next_c >= height) continue;
            if(map[next_c][next_r] == 1 && visited[next_c][next_r] == 0){
                visited[next_c][next_r] = 1;
                Q.push(make_pair(next_c, next_r));
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> width >> height;
    while(width != 0 && height != 0){
        for(int i=0; i< height ; i++){
            for(int j=0; j < width; j++){
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        
        sum = 0;
        for(int i=0; i< height ; i++){
            for(int j=0; j < width; j++){
                if(visited[i][j] == 0 && map[i][j] == 1){
                    bfs(i, j);
                    sum++;
                }
            }
        }
        cout << sum << endl;
        
        cin >> width >> height;
    }
}
