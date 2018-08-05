//  boj_n3055
//  https://www.acmicpc.net/problem/3055

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<vector<char> > map;
vector<vector<int> > timeMap;
pair <int, int> D;
queue<pair<int, int> > S;
queue<pair<int, int> > water;

void BFS(int ans){
    
    int wsize = water.size();
    for(int i=0; i<wsize; i++){
        int x = water.front().second;
        int y = water.front().first;
        water.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(map[ny][nx] == '.' || map[ny][nx] == 'S'){
                map[ny][nx] = '*';
                water.push({ny,nx});
            }
        }
    }
    
    int ssize = S.size();
    if(ssize == 0) {
        cout << "KAKTUS";
        return;
    }
    
    for(int i=0; i < ssize; i++){
        int x = S.front().second;
        int y = S.front().first;
        S.pop();
        for(int k = 0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(timeMap[ny][nx] == 1) continue;
            if(map[ny][nx] == '*' || map[ny][nx] == 'X') continue;
            if(map[ny][nx] == 'D') {
                cout << ans;
                return;
            }
            
            S.push({ny, nx});
            timeMap[ny][nx] = 1;
            
        }
    }
    
    ans++;
    
//
//        for(int i = 0; i < R; i++){
//            for(int j = 0; j < C; j++){
//                cout << map[i][j] << " ";
//            }
//            cout << endl;
//        }
    
    BFS(ans);
}


int main(int argc, const char * argv[]) {
    cin >> R >> C;
    map.resize(R, vector<char>(C));
    timeMap.resize(R, vector<int>(C, 0));
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            
            switch (map[i][j]) {
                case 'D':   D = {i, j}; break;
                case 'S':   S.push({i,j}); map[i][j] = '.'; break;
                case '*':   water.push({i,j});  break;
                default:    break;
            }
        }
    }
    
    BFS(1);
    return 0;
}
