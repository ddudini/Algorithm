//  https://www.acmicpc.net/problem/15684
//  backjoon question 15684

#include <iostream>
#include <vector>
using namespace std;

#define MAXNUM 300

int N, M, H, ans;

vector< vector<int> > map;

bool game(){
    for(int i = 1 ; i <= N ; i++){
        int cx = i;
        for(int j=1; j<= H; j++){
            if(map[j][cx] == 1)
                cx++;
            else if(map[j][cx-1] == 1)
                cx--;
        }
        
        if(i != cx) {
            return false;
        }
    }
    
    return true;
}

void dfs(int row, int cnt, int target){
    
    if(ans != MAXNUM) return;
    
    
    if(cnt == target){
        if( game() ) ans = cnt;
        return;
    }
    
    
    for(int i = row; i <= H; i++){
        for(int j=1; j < N; j++){
            
            if(map[i][j] == 1) {
                j++;
                continue;
            }
            
            if(map[i][j-1] == 0 && map[i][j+1] == 0) {
                map[i][j] = 1;
                dfs(i, cnt+1, target);
                map[i][j] = 0;
            }
        }
    }
    
    
}



int main(int argc, const char * argv[]){
    cin >> N >> M >> H;
    
    ans = MAXNUM;
    
    map.resize(H+1, vector <int> (N+2, 0));
    for(int i = 0; i< M; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    
    game();
    
    for(int i=0; i<4; i++){
        dfs(1, 0, i);
        if(ans != MAXNUM)
            break;
    }
    ans = ans > 3 ? -1 : ans;
    cout << ans;
    
}
