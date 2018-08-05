//  boj_9019
//  https://www.acmicpc.net/problem/9019

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;

char t[4] = {'D', 'S', 'L', 'R'};

int dslr(int s, char type){
    int result = 0;
    
    if(type == 'D'){
        result = (s * 2) % 10000;
        
    }
    else if(type == 'S'){
        result = s -1;
        if(result < 0) result = 9999;
    }
    else if(type == 'L'){
        int first = s / 1000;
        result = (s % 1000) * 10 + first;
    }
    else if(type == 'R'){
        int last = s % 10;
        result = (last * 1000) + s / 10;
    }
    
    return result;
};

void bfs(int ss, int es){
    
    queue<pair <int, string> > q;
    bool visitied[10001] = {false, };
    visitied[ss] = true;
    q.push( {ss, ""} );

    while(!q.empty()){
        int s = q.front().first;
        string path = q.front().second;
        q.pop();
        
        if(s == es) {
            cout << path << endl;
            return;
        }
        
        for(int i=0; i<4;  i++){
            int next = dslr(s, t[i]);
            if(next < 0 || next >=  10000) continue;
            if(visitied[next]) continue;
            q.push({next, path+t[i]});
            visitied[next] = true;
        }
    }
};



int main(){

    int T;
    cin >> T;
    for(int i=0; i < T; i++){
        int t1, t2;
        cin >> t1 >> t2;
        bfs(t1, t2);
    }
}
