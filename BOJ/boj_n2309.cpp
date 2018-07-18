#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int man[9];
vector <int> man2;

int dfs(int idx, int sum){
    if(idx >= 9){
        if(sum == 100) return sum;
        else return -1;
    }

    dfs(idx+1, sum);
    man2.push_back(idx);
    dfs(idx+1, sum + man[idx]);
   
}
int main(){
    int man[9];
    for(int i=0; i<9; i++){
        cin >> man[i];
    }
    
    sort(man, man+9);

    int ans = dfs(0, 0);
    for(int i=0 ; i < man2.size(); i++){
        cout << man2[i];
    }
    

}