//
//  main.cpp
//  ss_1206
#include <iostream>
#include <vector>
using namespace std;

int buildingNum;
int building[1001];

int main(int argc, const char * argv[]) {
    for(int tc = 1; tc <= 10; tc++){
        cin >> buildingNum;
        
        for(int i=0 ; i < buildingNum ; i++)
            scanf("%d", &building[i]);
        
        int sum = 0;
        
        for(int i=2; i < buildingNum-2 ; i++){
            int lmax = max(building[i-1], building[i-2]);
            int rmax = max(building[i+1], building[i+2]);
            int maxh = max(lmax, rmax);
            if(building[i] > maxh) {
                sum = sum + (building[i]-maxh);
                i += 2;
            }
        }
        printf("#%d %d\n", tc, sum);
    }
    return 0;
}
