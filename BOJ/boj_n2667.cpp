//
//  boj_2667
//  backjoon 2667번
//  https://www.acmicpc.net/problem/2667
//  Created by Sujin Han on 2018. 7. 14..
//  Copyright © 2018년 ddudini. All rights reserved.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int size;
int map[25][25];
int visited[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int houseNum[3125];
int Count;

void dfs(int r, int c, int cnt){
    visited[r][c] = 1;
    houseNum[cnt]++;
    
    for(int i = 0; i < 4 ; i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr<0 || nr >= size || nc < 0 || nc >= size) continue;
        if(visited[nr][nc] == 1) continue;
        if(map[nr][nc] == 0) continue;
        
        dfs(nr, nc, cnt);
        
    }
}

int main(int argc, const char * argv[]) {
    cin >> size;
    string temp;
    for(int i=0; i < size ; i++){
        for(int j=0; j < size ; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i < size ; i++){
        for(int j=0 ; j < size ; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                dfs(i, j, Count);
                Count++;
            }
        }
    }
    
    sort(houseNum, houseNum + Count);
    cout << Count << endl;
    for(int i= 0 ; i < Count ; i++){
        cout << houseNum[i] << endl;
    }
}













