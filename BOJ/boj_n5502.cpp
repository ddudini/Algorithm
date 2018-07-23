// https://www.acmicpc.net/problem/5502
// boj number 5502

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string inputS;

vector < vector <int> > lcs;

int solution(){
    inputS = " "+inputS;
    
    string inputS2 = " ";
    for(int i=N; i>=1; i--)
        inputS2 += inputS[i];
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <=N ; j++){
            if(inputS[i] == inputS2[j]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }
    return N-lcs[N][N];
        
}


int main(int argc, const char * argv[]) {
    cin >> N >> inputS;
    inputS = inputS;
    lcs = vector< vector<int> > (inputS.size() + 1, vector <int> (inputS.size()+1, 0));
    cout << solution();
    
    return 0;
}
