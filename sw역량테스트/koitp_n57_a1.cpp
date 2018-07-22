//
//  main.cpp
//  SDS_TEST_SPACE
//  https://koitp.org/problem/SDS_TEST_SPACE/read/
//  Created by Sujin Han on 2018. 7. 18..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int tc = 1;  tc <= t; tc++){
        int N, M, sx, sy, gx, gy;
        cin >> N >> M >> sx >> sy >> gx >> gy;
        
        
        int x_over = gx > sx ? sx + (N-gx) : gx + (N-sx);
        int x_move = abs(sx-gx);
        int y_over = gy > sy ? sy + (M-gy) : gy + (M-sy);
        int y_move = abs(sy-gy);
        
        int ans = min(x_over+y_over, x_move + y_move);
        ans = min(ans, y_over+x_move);
        ans = min(ans, x_over+y_move);
        
        printf("#%d %d\n", tc, ans);
        
    }
    return 0;
}
