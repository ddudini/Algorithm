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

#define INF 1000000

struct node {
    int end;
    int weight;
    
};

vector < vector <node> > graph;
vector<vector <int> > dist;

int n, m;

void dijkstra(int start_vertex){
    priority_queue< pair <int, int> > pq;
    pq.push( {0, start_vertex} );
    dist[start_vertex][start_vertex] = 0;
    
    while(!pq.empty()){
        int t = pq.top().second;
        int d = -1 * pq.top().first;
        pq.pop();

        for(int i=0; i< graph[t].size(); i++){
            int before = dist[start_vertex][ graph[t][i].end ];
            int later = dist[start_vertex][t] + graph[t][i].weight;
            
            if(before == -1 ||before > later){
                dist[start_vertex][graph[t][i].end] = later;
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
        graph[t].push_back(node{f, w});
    }
    
    int start, end;
    cin >> start >> end;
    
    dist.resize(n+1, vector<int>(n+1, INF));
    
    dijkstra(1);
    dijkstra(start);
    dijkstra(end);
    
    int ans = min(dist[1][start] + dist[start][end] + dist[end][n], dist[1][end]+dist[end][start] + dist[start][n]);
    
    ans = ans > INF ? -1: ans;
    cout << ans;
    return 0;
}
