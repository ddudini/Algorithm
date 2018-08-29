//  https://www.acmicpc.net/problem/11438
//  boj 11438
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int parent[100001];


int depth(int idx){
    int d = 0;
    while(idx != 1){
        idx = parent[idx];
        d++;
    }
    return d;
}

int LCA(int a, int b){
    int da = depth(a);
    int db = depth(b);
    int diff = abs(da-db);
    if(da<db) swap(a, b);
    
    while(diff--){
        a = parent[a];
    }
    
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

int main(){
    cin >> N;
    parent[1] = 1;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        if(!parent[a]) parent[a] = b;
        if(!parent[b]) parent[b] = a;
    }

    int M;
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
}
