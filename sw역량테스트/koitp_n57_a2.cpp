//
//  main.cpp
//  SDS_TEST_SURVIVOR
//  https://koitp.org/problem/SDS_TEST_SURVIVOR/read/
//  Created by Sujin Han on 2018. 7. 18..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
using namespace std;

int map[10][10];
int map_size;

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

int check(int i, int j){
    bool check[4] = {false, false, false, false};
    check[map[i][j]] = true;
    for(int k = 0; k < 8 ; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        
        if(ni < 0 || nj < 0 || ni >= map_size || nj >= map_size) continue;
        if(map[ni][nj] == 0) return 0;
        check[map[ni][nj]] = true;
    }
    if(check[1] && check[2] && check[3]) return 1;
    else return 0;
    
}
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int tc = 1;  tc <= t; tc++){
        cin >> map_size;
        for(int i=0; i< map_size; i++){
            for(int j=0; j < map_size; j++){
                cin >> map[i][j];
            }
        }
        
        int ans = 0;
        for(int i=0; i< map_size; i++){
            for(int j=0; j < map_size; j++){
                if(map[i][j] != 0) ans += check(i, j);
                else j++;
            }
        }
       printf("#%d %d\n", tc, ans);
        
    }
    return 0;
}
