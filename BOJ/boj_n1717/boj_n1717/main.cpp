//
//  main.cpp
//  boj_n1717
//  https://www.acmicpc.net/problem/1717
//  Created by Sujin Han on 2018. 7. 17..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int parent[1000100];
int n, m;

int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void add(int a, int b){
    int pa = find(a);
    int pb = find(b);
    parent[pb] = pa;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    for(int i=0; i<=n ;i++)
        parent[i] = i;
    
    while(m--){
        
        int op, a, b;
        cin >> op >> a >> b;
        
        if(op == 0) add(a, b);
        else {
            
            int pa = find(a);
            int pb = find(b);
            
            if(pa == pb) cout <<"YES\n";
            else cout << "NO\n";
        }
    }
    for(int i=0; i<=n ;i++)
        cout << parent[i] << " ";
    return 0;
}

/*
 7 8
 0 1 3
 1 1 7
 0 7 6
 1 7 1
 0 3 7
 0 4 2
 0 1 1
 1 1 1
 */
