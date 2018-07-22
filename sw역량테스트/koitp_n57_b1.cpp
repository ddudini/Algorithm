//  SDS_TEST_TREASURE
//  https://koitp.org/problem/SDS_TEST_TREASURE/read/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 10100
using namespace std;

int N, M, K;
vector <vector <int> > Graph;
vector <int> Depth;

void BFS(int startV){
    queue <int> Q;
    Depth[startV] = 0;
    Q.push(startV);
    
    while(!Q.empty()){
        int curV = Q.front();
        Q.pop();
        for(int i=1 ;  i <= N ; i++){
            if(Graph[curV][i] == 1){
                Q.push(i);
                Graph[curV][i] = 0;
                Depth[i] = min(Depth[i], Depth[curV] + 1);
            
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int tc = 1;  tc <= t; tc++){
        cin >> N >> M >> K;
        Graph = vector <vector <int> > (N+1, vector <int> (N+1, 0));
        Depth = vector<int> (N+1, INF);
        
        for(int i=0; i < M; i++){
            int f, t;
            cin >> f >> t;
            Graph[f][t] = 1;
        }
        
        BFS(1);
    
        
        int ans = Depth[N] <= K ? Depth[N] : -1;
        printf("#%d %d\n", tc, ans);
        
    }
    return 0;
}
