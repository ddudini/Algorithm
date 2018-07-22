//
//  main.cpp
//  SDS_TEST_PAGE
//  https://koitp.org/problem/SDS_TEST_PAGE/read/
//  Created by Sujin Han on 2018. 7. 18..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, S, J, K, kidx;
int kpages[1000];

int check(int cur_page){
    while(kpages[kidx] < cur_page){
        kidx++;
        if(kidx >= K) return 0;
    }
    
    if(kpages[kidx] == cur_page){
        kidx++;
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int tc = 1;  tc <= t; tc++){
        cin >> N >> S >> J >> K;
        for(int i=0 ; i < K ; i++)
            cin >> kpages[i];
        
        sort(kpages, kpages+K);
        kidx = 0;
        int ans = 0;
        int cur_page = S;
        
        while(cur_page <= N){
            if(kidx < K)
                ans += check(cur_page);
            cur_page += J+1;
        }
        printf("#%d %d\n", tc, ans);
        
    }
    return 0;
}
