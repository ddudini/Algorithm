//
//  main.cpp
//  boj_n11403
//  https://www.acmicpc.net/problem/11403
//  Created by Sujin Han on 2018. 7. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//  플로이드 위셜 알고리즘
//  i 에서 k 로 가는 경로 존재 & k 에서 j로가는 경로 존재 -> i 에서 j 로가는 경로 존재.

#include <iostream>
#include <vector>
using namespace std;

int map[100][100];
int ans[100][100];
vector <vector <int> > visited;

int N;

int main(int argc, const char * argv[]) {
    cin >> N;
    
    visited.resize(N, vector<int>(N, 0));
    
    for(int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            cin >> map[i][j];
        }
    }
    
    for(int k=0; k < N; k++){
        for(int i=0; i< N; i++){
            for(int j=0; j< N ; j++){
                if(map[i][k] == 1 && map[k][j] == 1)
                    map[i][j] = 1;
            }
        }
        
    }
    
    
    for(int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
