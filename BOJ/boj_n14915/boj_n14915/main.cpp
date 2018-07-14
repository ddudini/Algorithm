//
//  main.cpp
//  boj_n14915
//
//  Created by Sujin Han on 2018. 6. 15..
//  Copyright © 2018년 ddudini. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
    cin >> m >> n;
    
    string arr[16] = {"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    
    string answer = "";
    string temp;
    while(m){
        answer = arr[m%n]+ answer;
        m /= n;
    }
    if(answer == "")
        answer = "0";
    cout << answer;
    return 0;
}
