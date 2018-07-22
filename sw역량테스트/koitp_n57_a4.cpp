#include <iostream>
#include <vector>
using namespace std;

int N, K, L;
int cusTime[10000];
int cusNegTime[10000];
int dp[1000000];
vector < vector <int> > cusXtime;
void solution(){
    cusXtime = vector < vector <int> > (N);
    for(int i=0; i < L/K; i++){
        cusXtime[i] = vector<int> (cusTime[i]);
        
        cusXtime[i][0] = i > 0 ? cusXtime[i-1][5] - cusTime[i] : - cusTime[i];
    
        for(int j = 1; j < cusTime[i]; j++){
            cusXtime[i][j] = cusXtime[i][j-1] + 1 + cusNegTime[i];
        }
    }
    
    for(int i=0; i < L/K; i++){
        cout << "customer " << i << ": ";
        for(int j = 0; j < cusTime[i]; j++){
            cout << cusXtime[i][j] << " ";
        }
        cout << endl;
    }
    
    dp[0] = cusXtime[0][K];
    
    for(int i=1; i < L/K; i++){
        dp[i*K] = dp[(i-1)*K];
        for(int j = i * K + 1; j < (i+1) * K ; i++){
            int temp = dp[j-1];
            for(int k = 1; k < i ; k++){
                if(j < cusTime[k]) temp += j;
            }
        }
    }
    
}


int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++){
        cin >> N >> K >> L;
        for(int i=0; i < N; i++)
            cin >> cusTime[i] >> cusNegTime[i];
    }
    solution();
    
}
