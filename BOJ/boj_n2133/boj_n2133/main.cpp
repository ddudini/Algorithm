//
//  main.cpp
//  boj_n2133
//https://www.acmicpc.net/problem/2133
//  Created by Sujin Han on 2018. 6. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int dp[30];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    
    for(int i = 3; i <= n ; i++){
        dp[i] = dp[i-2]*3;
        for(int j = i-4; j >=0 ; j-=2){
            dp[i] += 2*dp[j];
        }
    }

    cout << dp[n];
    return 0;
}
