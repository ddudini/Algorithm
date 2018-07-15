//https://www.acmicpc.net/problem/14620
//boj 14620
/*
 6
 1 0 2 3 3 4
 1 1 1 1 1 1
 0 0 1 1 1 1
 3 9 9 0 1 99
 9 11 3 1 0 3
 12 3 0 0 0 1
 ->!2
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
int map[10][10];
int dp[10][10];
bool visited[10][10];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

vector <int> fx;
vector <int> fy;

int min_pay = 200 * 10 * 10;

int getPrice(int x, int y){
    int sum=0;
    for(int i=0; i< 5; i++){
        sum += map[x+dx[i]][y+dy[i]];
    }
    return sum;
}
bool isOK(int x, int y){
    for(int i=0; i< 5; i++){
        if(visited[x+dx[i]][y+dy[i]])
            return false;
    }
    return true;
}
void dfs(int x, int y, int cnt, int sum){
    if (cnt == 3){
        /*
        for(int i=0 ; i < fx.size(); i++){
            cout << "(" << fx[i] << "," << fy[i] << ")";
        }
        cout <<"\n";
         */
        min_pay = min(min_pay, sum);
        return;
    }
    
    for(int i = x; i < N-1 ; i++){
        for(int j = 1; j < N-1 ; j++){
            if(isOK(i, j)){
                for(int k=0; k< 5; k++){
                    visited[i+dx[k]][j+dy[k]] = true;
                }
                fx.push_back(i);
                fy.push_back(j);
                dfs(i, j, cnt+1, sum+dp[i][j]);
                
                for(int k=0; k< 5; k++){
                    visited[i+dx[k]][j+dy[k]] = false;
                }
                fx.pop_back();
                fy.pop_back();
            }
        }
    }
    

}
int main(int argc, const char * argv[]) {
    cin >> N;
    
    for(int i=0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=1; i < N-1 ; i++){
        for( int j = 1; j < N-1 ; j++){
            dp[i][j] = getPrice(i, j);
        }
    }
    
    dfs(1,1,0,0);
    cout << min_pay;
    return 0;
}
