//
//  main.cpp
//  boj_n1197
//  https://www.acmicpc.net/problem/1197
//  Created by Sujin Han on 2018. 7. 16..
//  Copyright © 2018년 ddudini. All rights reserved.
//
/*
 3 3
 1 2 1
 2 3 2
 1 3 3
 
 3 4
 1 2 4
 2 3 2
 1 3 3
 2 1 1
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Edge {
    int from;
    int to;
    int weight;
    bool operator>(const Edge & e) const {return weight > e.weight;};
    Edge(int f, int t, int w){from = f; to = t; weight = w;};
};

int V, E, sum;
vector<int> parent;

int findSet(int u){
    while(u != parent[u]){
        u = parent[u];
    }
    return u;
}

int main(int argc, const char * argv[]) {
    
    cin >> V >> E;
    
    parent.resize(V+1, 0);
    
    for(int i=1; i< V+1; i++){
        parent[i] = i;
    }
    
    priority_queue<Edge, vector <Edge>, greater<Edge> > Q;
    
    for(int i=0; i< E; i++){
        int f, t, w;
        cin >> f >> t >> w;
        Q.push(Edge(f, t, w));
    }
    
    while (!Q.empty()){
        Edge e = Q.top();
        Q.pop();
        
        int fromSet = findSet(e.from);
        int toSet = findSet(e.to);
        
        if(fromSet != toSet){
            parent[toSet] = fromSet;
            sum += e.weight;
        }
        
        
    }
    
    cout << sum;

    return 0;
}
