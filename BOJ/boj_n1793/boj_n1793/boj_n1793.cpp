//
//https://www.acmicpc.net/problem/11727
//BOJ 11727
//  Created by Sujin Han on 2018. 6. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int dp[1000];
    
    int n;
    cin >> n;
    
    dp[0] = 0;
    dp[1]= 1;
    dp[2] =3;
    for(int i = 3; i<= n ; i++){
        dp[i] = (dp[i-1] + (2 * dp[i-2]) % 10007 ) %  10007;
    }
    cout << dp[n];
    return 0;
}

