#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {
    stack <char> left;
    stack <char> right;

    string in;
    cin >> in;
    for(int i=0 ; i < in.size() ; i++){
        left.push(in[i]);
    }

    int testcase;
    cin >> testcase;
    
    for(int t = 0 ; t < testcase ; t++){
        char op, op2;
        cin >> op;
        if(op == 'P') cin >> op2;
        
        switch (op) {
            case 'L':
                if(left.empty()) break;
                else {
                    right.push(left.top());
                    left.pop();
                }
                break;
            case 'D':
                if(right.empty()) break;
                else {
                    left.push(right.top());
                    right.pop();
                }
                break;
            case 'B':
                if(left.empty()) break;
                else left.pop();
                break;
            case 'P':
                left.push(op2);
                break;
            default:
                break;
        }

    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    
    
}