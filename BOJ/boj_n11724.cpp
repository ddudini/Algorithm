//
//  main.cpp
//  boj_n11724
//  https://www.acmicpc.net/problem/11724
//  Created by Sujin Han on 2018. 7. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int VN, EM;
int map[1001][1001];
int visited[1001];

int main(int argc, const char * argv[]) {
    cin >> VN >> EM;
    for(int i= 0 ; i < EM;  i++){
        int from, to;
        cin >> from >> to;
        map[from][to] = 1;
        map[to][from] = 1;
    }
    
    int total = 0;
    for(int i=1; i <= VN ; i++){
        if(visited[i] == 0){
            //bfs
            queue<int> Q;
            
            Q.push(i);
            visited[i] = 1;
            total++;
            
            while(!Q.empty()){
                int cur = Q.front();
                Q.pop();
                for(int j = 1; j <= VN; j++){
                    if(map[cur][j] == 1 && visited[j] == 0){
                        Q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    
    cout << total << endl;
}
