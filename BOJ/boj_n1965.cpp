#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair <int,int>  A, pair <int, int> B){
	if(A.second == B.second){
		return A.first < B.first ? true: false;
	}
	else 
		return A.second < B.second ? true: false;
}

int main(){
	int n;
	cin >> n;
	int max = 0;
	vector <pair <int, int> > sumarr =. vector <pair <int, int> > (n);
	vector <int> arr = vector <int>(n);

	int count = 0;
	for(int i=0 ; i < n ; i++){
		cin >> arr[i];
		if(i==0){
			sumarr[0] = make_pair(count, arr[i]);
		}
		else {
			if(arr[i] > sumarr[i-1].second){
				sumarr[i] = make_pair(sumarr[i-1].first+1, arr[i]);
			}
			else {
				sumarr[i] = make_pair()
			}
		}
	
	}


	cout << max;
}