//  boj_n2309
//  https://www.acmicpc.net/problem/2309

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int E, S, M;

    cin >> E >> S >> M;
    
    int e, s, m;
    e=s=m=1;
    int y  = 0;
    
    while(++y){
        if(E == e && S == s && M == m){
            cout << y << endl;
            break;
        }
        
        e = (e % 15) + 1;
        s = (s % 28) + 1;
        m = (m % 19) + 1;
    }
    return 0;
}
