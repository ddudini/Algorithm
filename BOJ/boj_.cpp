//  boj 2805
//  https://www.acmicpc.net/problem/2805

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> queue;
int sidx, eidx;
int push(int x);
int pop();
int front();
int back();
int size();
int empty();

int N;

int main(){
    
    cin >> N;
    
    while(N--){
        string op;
        cin >> op;
        if(op == "push"){
            int op2;
            cin >> op2;
            push(op2);
        }
        else if(op == "pop") cout << pop() << endl;
        else if(op == "front") cout << front() << endl;
        else if(op == "back") cout << back() << endl;
        else if(op == "size" )cout << size() << endl;
        else if(op == "empty") cout << empty() << endl;
    }
    
    
 
}

int push(int x) {
    queue.push_back(x);
    eidx++;
    return x;
}
int pop(){
    if(empty()) return -1;
    else return queue[sidx++];
}
int front() {
    if(empty()) return -1;
    else return queue[sidx];
}
int back() {
    if(empty()) return -1;
    else return queue[eidx-1];
}
int size(){
    return eidx-sidx;
}
int empty(){
    if(eidx == sidx) return 1;
    else return 0;
}
