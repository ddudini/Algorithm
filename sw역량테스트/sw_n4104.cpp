
/*
 
 10

 */

#include <iostream>
#include <vector>
using namespace std;

int N, X;
int map[42][21];
vector <int> slide; //0 none 1 right 2 left
int sum;

bool putSlide(int i, int j, bool Right){
    
    if(Right){
        if(j+X >= N) return false;
        
        for(int k = X; k > 0; k--){
            if(map[i][j] - map[i][j+k] != 1) return false;
            if(slide[j+k] == 2) return false;
        }
        for(int k = X; k > 0; k--){
            slide[j+k] = 1;
        }
        
    }
    else {
        if(j-X < 0) return false;
        
        for(int k=X; k > 0 ; k--){
            if(map[i][j] - map[i][j-k] != 1) return false;
            if(slide[j-k] == 1) return false;
        }
        for(int k = X; k > 0; k--){
            slide[j-k] = 2;
        }
    }
    
    return true;
}
void solution() {
    for(int i=0; i<2*N; i++){
        slide.assign(N, 0);
        bool flag = true;
        for(int j = 0; j < N-1; j++){
            int diff = map[i][j] - map[i][j+1];
            if(diff == 0) continue;
            else if(diff == 1){
                if(!putSlide(i, j, true)){
                    flag = false;
                    break;
                }
            }
            else if (diff == -1){
                if(!putSlide(i, j+1, false)){
                    flag =false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
            
        }
        if(flag) {
            sum++;
        }
    }
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for(int tc = 1; tc <= T; tc++){
        cin >> N >> X;
        for(int i=0; i< N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        for(int i=N; i< 2*N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = map[j][i-N];
            }
        }
        slide.resize(N, 0);
        sum = 0;
        solution();
        
        printf("#%d %d\n", tc, sum);
    }
    return 0;
}
