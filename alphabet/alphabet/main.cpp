/*
 https://www.acmicpc.net/problem/1157
 N. 1157 단어공부
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    string word;
    cin >> word;
    int asci[26] = {0};
    
    
    for(int i=0 ; i<word.length() ; i++){
        if(word.at(i) >= 'A' && word.at(i) <= 'Z')
            asci[word.at(i) - 'A']+=1;
        else
            asci[word.at(i) - 'a']+=1;
    }
    int max = -1;
    char out;
    for (int i=0 ; i < 26 ; i++){
        if(max < asci[i]){
            max = asci[i];
            out = i + 'A';
        }
        else if (max == asci[i]){
            out = '?';
        }
    }
    cout << out;
}
