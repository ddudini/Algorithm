//  boj_n15685
//  https://www.acmicpc.net/problem/15685

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Dragon{
public:
    int x;
    int y;
    vector<int> dir;
    int g;
    
    Dragon(int x_, int y_, int d_, int g_):x(x_), y(y_), g(g_) {dir.push_back(d_);};
    
    void setDragon(int x_, int y_, int d_){
        x = x_; y = y_;
        dir.push_back(d_);
    }
    
};

int N;
int map[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

vector<Dragon> dragons;

int solution(){
    int sum = 0;
    for(int i=0; i<100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
                sum++;
        }
    }
    return sum;
}
void printMap(int r, int c){
    for(int i = 0;  i < c ; i++){
        for(int j=0; j < r; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void GenerateDragon(int idx,int gc){
    if(dragons[idx].g < gc) return;
    
    int cx = dragons[idx].x;
    int cy = dragons[idx].y;
    int d;
    
    if(gc == 0){
        d = dragons[idx].dir[0];
        map[cy][cx] = 1;
        cx += dx[d];
        cy += dy[d];
        map[cy][cx] = 1;
        dragons[idx].x = cx;
        dragons[idx].y = cy;
//        d = changeDirection(d, Clock);
        
    }
    else {
        int Size = dragons[idx].dir.size();
        for(int i=Size-1; i >= 0; i--){
            d = dragons[idx].dir[i];
            d = (d+1)%4;
            
            cx += dx[d];
            cy += dy[d];
            
            map[cy][cx] = 1;
            
            dragons[idx].setDragon(cx, cy, d);
        }
        
    }
    
    GenerateDragon(idx, gc+1);
}

int main(int argc, const char * argv[]) {
    cin >> N;

    for(int i=0; i< N; i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        dragons.push_back(Dragon(y, x, d, g));
    }

    for(int i=0; i<dragons.size(); i++){
        GenerateDragon(i, 0);
//        printMap(10, 10);
    }
    
    cout << solution();
    return 0;
}
