//  https://www.acmicpc.net/problem/2042
//  boj 2042

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M, K;

int Nidx;
int MaxIdx;
vector<int>arr;

int depth(int n) {
    int depth = log(n) / log(2);
    if(pow(2, depth) != n) depth++;
    return depth;
}

void buildTree(int idx){
    if(idx >= Nidx) return;
    
    buildTree(idx*2);
    buildTree(idx*2+1);
    arr[idx] = arr[idx*2] + arr[idx*2+1];
}

void changeNumber(int idx, int num){
    int cidx = Nidx+idx-1;
    arr[cidx] = num;
    while(cidx > 1) {
        cidx = cidx - cidx%2;
        arr[cidx/2] = arr[cidx] + arr[cidx+1];
        cidx /= 2;
    }
}

int findSum(int sidx, int eidx){
    int sum = 0;
    sidx = Nidx + sidx -1;
    eidx = Nidx + eidx -1;
    while(sidx <= eidx) {
        if(sidx % 2 == 1) sum += arr[sidx++];
        else sidx/=2;
        
        if(eidx % 2 == 0) sum += arr[eidx--];
        else eidx/=2;
    }
    
    return sum;
}
int main(){
    cin >> N >> M >> K;
    Nidx = pow(2, depth(N));
    MaxIdx = Nidx*2;
    arr.resize(MaxIdx+1, 0);
    for(int i = Nidx; i<Nidx+N; i++){
        cin >> arr[i];
    }

    buildTree(1);
    
    for(int i=0; i< M+K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) changeNumber(b, c);
        else if(a == 2) cout << findSum(b, c) << endl;
        
//        cout << endl;
//        for(int i=1; i<MaxIdx; i++)
//            printf("%2d ", i);
//        cout << endl;
//        for(int i=1; i<MaxIdx; i++)
//            printf("%2d ", arr[i]);
//        cout << endl;
    }
    
    
}
