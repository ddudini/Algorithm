#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;
int start_node_num, V, E;

struct NODE {
    int end;
    int val;
};

// 0번 인덱스는 버린다.
vector<NODE> G[MAX_E];
// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_V] = { 0 };

void dijkstra() {
    priority_queue< pair<int,int> > pq;
    pq.push({ 0, start_node_num });
    
    while (!pq.empty()){
        int now_node = pq.top().second;
        int cost = -1 * pq.top().first;
        pq.pop();
        
        for (int k = 0; k < G[now_node].size(); k++) {
            int new_val = dist[now_node] + G[now_node][k].val;
            int before_val = dist[G[now_node][k].end];
            if (new_val < before_val) {
                dist[G[now_node][k].end] = new_val;
                pq.push({ -1*new_val, G[now_node][k].end });
            }
        }
        
    }
}

int main(){
    cin >> V >> E >> start_node_num;
    
    int from, to, val;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &val);
        G[from].push_back(NODE{ to, val });
    }

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[start_node_num] = 0;
    dijkstra();
    
    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF) printf("%d\n", dist[i] );
        else printf("INF\n");
    }
    
    return 0;
}
