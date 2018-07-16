//
//  main.cpp
//  boj_n1916
//  https://www.acmicpc.net/problem/1916
//  Created by Sujin Han on 2018. 7. 16..
//  Copyright © 2018년 ddudini. All rights reserved.

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define MAXV 10000
#define MAXE 1000000

struct node {
    int end;
    int weight;
    
};

vector < vector <node> > graph;
vector<int> dist;
int n, m;

void dijkstra(int start_vertex){
    priority_queue< pair <int, int> > pq;
    pq.push( {0, start_vertex} );
    dist[start_vertex] = 0;
    
    while(!pq.empty()){
        int t = pq.top().second;
        int d = -1 * pq.top().first;
        pq.pop();
        
        for(int i=0; i< graph[t].size(); i++){
            int before = dist[ graph[t][i].end ];
            int later = dist[t] + graph[t][i].weight;
            
            if(before == -1 ||before > later){
                dist[graph[t][i].end] = later;
                pq.push( {-1 * later, graph[t][i].end} );
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> n >> m;
    graph.resize(n+1);
    
    for(int i=0; i < m; i++){
        int f, t, w;
        cin >> f >> t >> w;
        graph[f].push_back(node{t, w});
    }
    
    dist.resize(n+1, -1);
    int start, end;
    cin >> start >> end;
    
    dijkstra(start);
    
    cout << dist[end];
    
    return 0;
}
