//  https://www.acmicpc.net/problem/11438
//  boj 11438
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> Graph[100001];
//int parent[100001];
int H;
int parent[17][100001];
int depthV[100001];
int visited[100001];

void dfs(int idx, int cnt){
    if(idx > N){
        return;
    }
    
    H = max(H, cnt);
    depthV[idx] = cnt;
    for(int n: Graph[idx]){
        if(parent[0][n]) continue;
        
        parent[0][n] = idx;
        dfs(n, cnt+1);
    }
}

void updateParent(){
    for(int v = 2; v <= N; v++){
        int max2k = log(depthV[v]) / log(2);
        for(int k = 1; k <= max2k ; k++){
            parent[k][v] = parent[k-1][ parent[k-1][v] ];
        }
    }
    
}

void updateParent(int v){
    if(v == 1) return;
    if(visited[v]) return;
    visited[v] = 1;
    
        int max2k = log(depthV[v]) / log(2);
        for(int k = 1; k <= max2k ; k++){
            parent[k][v] = parent[k-1][ parent[k-1][v] ];
        }
    
    
}

int LCA(int a, int b){
    if(a == 1 || b == 1) return 1;
    
    updateParent(a);
    updateParent(b);
    int diff = depthV[a] - depthV[b];
    
    int na, nb;
    if(diff >= 0) {
        na = a; nb = b;
    }
    else {na = b; nb = a;}
    diff = abs(diff);
    
    for(int cnt = 0; diff != 0; cnt++) {
        int flag = diff & 1;
        diff = diff >> 1;
        if(flag){
            na = parent[cnt][na];
        }
    }
//    printf("%d %d", na, nb);
    
    while(na != nb) {
        na = parent[0][na];
        nb = parent[0][nb];
    }
    return na;
    
}

int main(){
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    parent[0][1] = 1;
    dfs(1, 0);
    
//    cout << H;
    
    int M;
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
}
