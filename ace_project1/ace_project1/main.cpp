#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> v) {
    int answer = 0;
    int sum = 0;
    int l_sum[n+1];
    
    l_sum[0] = 0;
    for(int i=0; i < n ; i++){
        sum += v[i];
        l_sum[i+1] = v[i] + l_sum[i];
    }
    

    int min_arr[n+1];
    
    int min_diff = 1000 * 30000;
    int index = 0;;

    for(int i=0; i < n+1 ; i++){
        min_arr[i] = abs(l_sum[i] - (sum - l_sum[i]));
        //cout << min_arr[i] << "min_arr ";
        
        if(min_diff > min_arr[i]){
            min_diff = min_arr[i];
            index = i;
            //cout <<"index" << i << " ";
        }
    }

   //cout << "\n";
    answer = index;
    return answer;
}

int main(){
    vector<int> v = {1, 2, 1, 2, 1};
    cout << solution(5, v);
}
