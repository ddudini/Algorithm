#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(pair<int, char> s, pair<int, char> s2){
    if(s.second == s2.second)
        return s.first < s2.first ? true: false;
    return s.second > s2.second ? true : false;
}
void Print(vector<pair <int, char> > &v){
    for(int i=0; i<v.size(); i++){
        cout << "[" << v[i].first << ", " << v[i].second << "]";
    }
    cout << endl;
}

string solution(string s) {
    
    vector <pair<int, char> > tt;
    
    for(int i=0 ; i< s.size() ; i++){
        tt.push_back( make_pair(i, s[i]) );
    }
    
    sort(tt.begin(), tt.end(), compare);
    //Print(tt);
    
    stringstream ss;
    string answer;
    ss <<tt[0].second;
    ss >> answer;
    
    int index = tt[0].first;
    
    for(int i=1 ; i < s.size() ; i++){
        if(tt[i].first > index){
            stringstream ss;
            string temp;
            ss << tt[i].second;
            ss >> temp;
            answer += temp;
            index = tt[i].first;
        }
    }
    return answer;
    
}
int main() {
    cout << solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafaaaaaaaafaaaaaaaabaaab");
}
