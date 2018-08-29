//  https://www.acmicpc.net/problem/11266
//  boj 11266
#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector <int> Graph[10001];
int vOrder[10001];
int cutVertex[10001];
int torder;

int dfs(int v, int pv){
    if(vOrder[v] != 0) return vOrder[v];    //방문한 노드;
    
    vOrder[v] = ++torder;
    int low = vOrder[v];
    
    int child = 0;
    for(int nv : Graph[v]){
        //if(nv == pv) continue;
        
        if(vOrder[nv] != 0) {
            low = min(low, vOrder[nv]);
            continue;
        }
        
        child++;
        int newLow = dfs(nv, v);
        if(pv != 0 && newLow >= vOrder[v]) cutVertex[v] = 1;
        low = min(low, newLow);
    }
    
    if(pv == 0 && child > 1) cutVertex[v] = 1;
    
//    printf("%d %d\n", v, low);
    return low;
}


int main(){
    scanf("%d %d", &V, &E);
    
    for(int i=0; i<E; i++){
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    for(int i=1; i<=V; i++){
        if(!vOrder[i]) dfs(i, 0);
    }
    
    vector<int> ans;
    for(int i=1; i<=V; i++){
        if(cutVertex[i]){
            ans.push_back(i);
        }
    }
    
    printf("%d\n", ans.size());
    for(int i=0; i< ans.size(); i++){
        printf("%d ", ans[i]);
    }
    puts("\n");
    
    
    
    return 0;
}
