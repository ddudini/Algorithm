//
//  main.cpp
//  boj_n2579
//  https://www.acmicpc.net/problem/2579
//  Created by Sujin Han on 2018. 6. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >>  n;
    int score[n];
    int dp[n];
    for(int i = 0 ; i < n ; i++){
        cin >> score[i];
        dp[i] = score[i];
    }
    
    if(n>=2) {
        dp[1] = score[0] + score[1];
    }
    if(n >= 3) {
        dp[2] = max(score[2] + score[0], score[1] + score[2]);
    }
    for(int i=3; i < n ; i++){
        int temp1 = score[i] + dp[i-2];
        int temp2 = score[i] + dp[i-3] + score[i-1];
        dp[i] = max(temp1, temp2);
    }
    
    cout << dp[n-1];
    return 0;
}
