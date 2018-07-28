//
//  main.cpp
//  boj_n15683
//  https://www.acmicpc.net/problem/15683
//  Created by Sujin Han on 2018. 7. 27..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class CCTV{
public:
    int x;
    int y;
    int type;
    vector <int> direction;
    CCTV(int y_, int x_, int t): x(x_), y(y_), type(t){};
};

int N, M, ans;
vector <vector <int> > map;
vector<CCTV> cctv;

void printMap(vector<vector<int> > arr){
    cout << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j < M; j++){
            if(arr[i][j] == -1)
                cout << "#" << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

int countBlank(vector<vector<int> > arr){
    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j < M; j++){
            if(arr[i][j] == 0) sum++;
        }
    }
    return sum;
}
void visitCamera(int x, int y, int dir, vector<vector<int> > & arr){
    
    if(dir == 0){   //to the right
        for(int i=x+1; i < M; i++){
            if(arr[y][i] == 6) return;
            else if (arr[y][i] > 0) continue;
            arr[y][i] = -1;
        }
        
    } else if(dir == 1){    //to the left
        for(int i = x-1; i >= 0 ; i--){
            if(arr[y][i] == 6) return;
            else if (arr[y][i] > 0) continue;
            arr[y][i] = -1;
        }
        
    } else if (dir == 2){   //to up
        for(int i=y-1; i >= 0; i--){
            if(arr[i][x] == 6) return;
            else if (arr[i][x] > 0) continue;
            arr[i][x] = -1;
        }
    } else if (dir == 3){
        for(int i= y+1; i < N; i++){
            if(arr[i][x] == 6) return;
            else if (arr[i][x] > 0) continue;
            arr[i][x] = -1;
        }
        
    }
}

void dfs(int idx){
    if(idx == cctv.size()){
        vector<vector<int>> visited = map;
        for(int i=0; i<cctv.size(); i++){
            for(int j=0; j < cctv[i].direction.size(); j++){
                visitCamera(cctv[i].x, cctv[i].y, cctv[i].direction[j], visited);
            }
        }
        
        int temp = countBlank(visited);
        ans = min(ans, temp);
//
//        cout << temp;
//        printMap(visited);
        
        return;
    }
    
    if(cctv[idx].type == 1){
        for(int i=0; i<4; i++){
            cctv[idx].direction = {i};
            dfs(idx+1);
        }
        
    } else if(cctv[idx].type == 2){
        for(int i=0; i<4; i+=2){
            cctv[idx].direction = {i, i+1};
            dfs(idx+1);
        }
    } else if(cctv[idx].type == 3){
        for(int i=0; i<2; i++){
            for(int j=2 ; j < 4; j++){
                cctv[idx].direction = {i, j};
                dfs(idx+1);
            }
        }
    } else if(cctv[idx].type == 4){
        for(int i=0; i<4; i++){
            cctv[idx].direction.resize(0);
            for(int j=0; j<4; j++){
                if(i==j) continue;
                cctv[idx].direction.push_back(j);
            }
            dfs(idx+1);
        }
        
    } else if(cctv[idx].type == 5){
        cctv[idx].direction = {0,1,2,3};
        dfs(idx+1);
    }
}

int main(int argc, const char * argv[]) {
    ans = 100;
    cin >> N >> M;
    map.resize(N, (vector<int>(M)));
    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cctv.push_back(CCTV(i,j,map[i][j]));
            }
        }
    }
    
    dfs(0);
    cout << ans;
    return 0;
}
