//
//  main.cpp
//  boj_n1012
//  https://www.acmicpc.net/problem/1012
//  Created by Sujin Han on 2018. 7. 14..
//  Copyright © 2018년 ddudini. All rights reserved.

#include <iostream>
#include <vector>
using namespace std;
int Count;

int T, width, height, CabageCount;
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
int map[50][50];
int visited[50][50];

void initilize(){
    for(int y = 0; y < height ; y++){
        for(int x=0; x < width ; x++){
            map[y][x] = 0;
            visited[y][x] = 0;
        }
    }
}
void dfs(int c, int r){
    visited[c][r] = 1;
    
    for(int i=0; i< 4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        
        if(nr < 0 || nc < 0 || nr >= width || nc >= height) continue;
        if(visited[nc][nr] == 1) continue;
        if(map[nc][nr] == 0) continue;
        dfs(nc, nr);
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &width, &height, &CabageCount);
        
        for(int i=0; i< CabageCount ; i++){
            int r, c;
            scanf("%d %d", &r, &c);
            map[c][r] = 1;
        }
        
        Count = 0;
        
        for(int i=0; i < height ; i++){
            for(int j=0; j < width; j++){
                if(map[i][j] == 0) continue;
                if(visited[i][j] == 1) continue;
                dfs(i, j);
                Count++;
            }
        }
        
        cout << Count << endl;
        
        initilize();
    }
    

}

