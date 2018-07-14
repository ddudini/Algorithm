#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

int main(){
	string in;
    cin >> in;

    int cuser = in.size();

    list <char> List;
    for(int i= 0 ; i < in.size() ; i++)
    	List.push_back(in[i]);

    int testcase;
    cin >> testcase;

    char op, op2;

    for(int t = 0 ; t < testcase; t++){
        cin >> op;

        if(op == 'P') cin >> op2;
        
        switch(op){
            case 'L':
                if(cuser == 0) break;
                else cuser--;
                break;
            case 'D':
                if(cuser == List.size()) break;
                else cuser++;
                break;
            case 'B':
                if(cuser == 0) break;
                else {
                    List.erase( cuser-1);
                    cuser--;
                }
                break;
            case 'P':
                List.insert(cuser, op2);
                cuser++;
                break;
        }
        //cout << cuser;
        //list.PrintList();


    }
 
}