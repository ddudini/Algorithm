#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int man[9];

void dfs(int idx, int& sum, vector<int> man2){
    if(idx >= 9){
        return;
    }
    
    dfs(idx+1, sum, man2);
    man2.push_back(idx);
    dfs(idx+1, &(sum + man[idx]), man2);
    
}
int main(){
    int man[9];
    for(int i=0; i<9; i++){
        cin >> man[i];
    }
    
    sort(man, man+9);
    
    
    vector <int> man2;
    int sum = 0;
    dfs(0, sum, man2);
    
    for(int i=0 ; i < man2.size(); i++){
        cout << man2[i];
    }
    
    
}
