
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int T,num;
int parent[200010];
int cnt[200010];
int id;
char f1[21];
char f2[21];

int find(int k){
    if(k == parent[k])
        return k;
    return parent[k] = find(parent[k]);
}

int merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x != y){
        parent[x] = y;
        cnt[y] += cnt[x];
        cnt[x] = 1;
    }
    return cnt[y];
}

int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    while(T--){
        
        scanf("%d", &num);
        map <string, int> m;
        for(int i=1; i<= 2*num; i++){
            parent[i] = i;
            cnt[i] = 1;
        }
        id = 1;
        for(int i=0; i< num; i++){
            scanf("%s %s", &f1, &f2);
            
            if(!m.count(f1)) {
                m[f1] = id++;
            }
            if(!m.count(f2)) {
                m[f2] = id++;
            }
            
            printf("%d\n", merge(m[f1], m[f2]));
        }
    }
    return 0;
}
 
