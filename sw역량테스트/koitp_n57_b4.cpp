/*
 13:80 -> 13:0
 0 0 0 0 1 1 0
 1 0 0 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 0
 
 1 8 : 8 0 -> 1 0 : 0 0
 0 0 0 0 1 1 0
 1 1 1 1 1 1 1
 1 1 1 1 1 1 1
 1 1 1 1 1 1 0
 
 18:00 -> 10:00
 0 0 0 0 1 1 0
 1 1 1 1 1 1 1
 1 1 1 1 1 1 0
 1 1 1 1 1 1 0
 
 -1 -1 : 0 8 -> 23:08
 1 0 1 1 0 1 0
 1 0 0 1 1 1 0
 1 1 1 1 1 1 0
 1 1 1 1 1 1 1
 
 -1 8 : 0 8 -> 18:00
 0 0 0 0 1 0 0
 1 1 1 1 1 1 1
 1 1 1 1 1 1 0
 1 1 1 1 1 1 1
 
 18:08 -> 10:0
0 0 0 0 1 1 0
1 1 1 1 1 1 1
1 1 1 1 1 1 0
1 1 1 1 1 1 1

 1 9 : 3 -1 -> 19:32
0 0 0 0 1 1 0
1 1 0 1 1 1 1
1 0 0 1 1 1 1
0 0 1 1 0 1 0
 
 5
 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 0 1
 0 0 0 0 1 1 0 1 1 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 0 1 0
 1 0 1 1 0 1 0 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1 1 1 1
 0 0 0 0 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0
 
 10 0
 0 25
 19 32
 23 8
 10 8
 10 0
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string digitalTime[10] = {
    "1111110",  //0
    "0000110",  //1
    "1011011",  //2
    "1001111",  //3
    "0100111",  //4
    "1101101",  //5
    "1111101",  //6
    "1000110",  //7
    "1111111",  //8
    "1101111"   //9
};

vector <int> ftime;
pair <int, string> Time[4];
int ans[2];
int maxTime[5] = {2, 9, 5, 9, 3};
vector <vector < pair <int, int> > > changeTime;    //바꿀수 있는 시간, 변경 횟수

void example(){
    for(int i=0; i < 10; i++) {
        printf("Find Different With %d: ", i);
        for(int j=0; j < 10; j++){
            if(i == j) continue;
            int diff = 0;
            for(int k = 0; k < 7 ; k++){
                if(digitalTime[i][k] == digitalTime[j][k]) continue;
                diff++;
                if(diff > 2) break;
            }
            if(diff <= 2){
                printf("(to %d, with %d) ", j, diff);
            }
        }
        cout << endl;
    }
}

void findFasterTime(int tidx, int & change){
    int midx = maxTime[tidx];
    int cidx = Time[tidx].first;
    if(tidx == 1 && Time[0].first == 2) midx = maxTime[4];
    
    for(int i=0; i < changeTime[cidx].size(); i++){
        if(changeTime[cidx][i].first > midx) break;
        if(changeTime[cidx][i].second > change) continue;
        
        Time[tidx].first = changeTime[cidx][i].first;
        change -= changeTime[cidx][i].second;
        break;
    }
}

void fixNumber(int tidx, int & change){
    int midx = maxTime[tidx];
    if(tidx == 1 && Time[0].first == 2) midx = 4;
    for(int i=0; i <= midx ; i++){
        int diff = 0;
        for(int j=0; j < 7 ; j++){
            if(Time[tidx].second[j] == digitalTime[i][j]) continue;
            diff++;
            if(diff > change) break;
        }
        if(diff <= change) {
            Time[tidx].first = i;
            Time[tidx].second = digitalTime[i];
            change = diff;
            break;
        }
    }
}

void solution(){
    
    int change = 2;
    
//    잘못 표시된 시간 고치기
    for(int i=0; i < ftime.size() ; i++){
        int fidx = ftime[i];
        
        int c = change;
        if(ftime.size() == 2) c = 1;
        fixNumber(fidx, c);
        change -= c;
    }
    
    
//    더 빠른 시간 찾기
    if(change != 0){
        for(int i=1; i < 4; i++){
            findFasterTime(i, change);
            if(change == 0) break;
        }
    }
    ans[0] = Time[0].first * 10 + Time[1].first;
    ans[1] = Time[2].first * 10 + Time[3].first;
}



int digitalToNum(string s){
    for(int i=0; i<10; i++){
        if(digitalTime[i] == s) return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    changeTime.resize(10);
    changeTime[3] = { {2, 2} };
    changeTime[4] = { {1, 2} };
    changeTime[5] = { {3, 2} };
    changeTime[6] = { {0, 2}, {5, 1} };
    changeTime[7] = { {1, 1}, {3, 2} };
    changeTime[8] = { {0,1}, {2, 2}, {3, 2}, {5, 2}, {6, 1}, {9,1} };
    changeTime[9] = { {0, 2}, {3, 1}, {4, 2}, {5, 1}, {6, 2}, {8, 1} };
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t ; tc++){
        
        ftime.resize(0);
        
        for(int i=0; i < 4; i++){
            
            string segment = "";
            
            for(int j=0; j<7; j++){
                string s;
                cin >> s;
                segment +=s;
            }
            Time[i].first = digitalToNum(segment);
            Time[i].second = segment;
            
            if(Time[i].first == -1 || Time[i].first > maxTime[i]) ftime.push_back(i);
        }
        if(Time[0].first == 2 && Time[1].first > maxTime[4]) ftime.push_back(1);
        
        solution();
//        example();
        printf("#%d %d %d\n", tc, ans[0], ans[1]);
        
    }
    return 0;
}
