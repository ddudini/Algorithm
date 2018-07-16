//
//  main.cpp
//  boj_n1922
//  https://www.acmicpc.net/problem/1922
//  Created by Sujin Han on 2018. 7. 16..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w){
        from = f;
        to = t;
        weight = w;
    }
    bool operator > (const Edge & e) const {return weight > e.weight;};
};

int N, M, sum;
vector <int> parent;
priority_queue<Edge, vector<Edge>, greater<Edge> > Q;
int find(int u){
    while(u != parent[u])
        u = parent[u];
    return u;
}
int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for(int i=0; i< M; i++){
        int v, u, w;
        cin >> v >> u >> w;
        Q.push(Edge(v, u, w));
    }
    
    parent.resize(N+1);
    for(int i=1; i < N+1; i++){
        parent[i] = i;
    }
    
    while(!Q.empty()){
        Edge cur = Q.top();
        Q.pop();
        
        int v = find(cur.from);
        int u = find(cur.to);
        if(v != u){
            sum += cur.weight;
            parent[u] = v;
        }
    }
    
    cout << sum;
    return 0;
}


















