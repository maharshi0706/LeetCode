#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string S;
        string T;
        cin>>S;
        cin>>T;
        string output;
        for(int i = 0;i < S.length(); i++){
            if(S[i] == T[i]) output += 'G';
            else output += 'B';
        }
        cout<<output<<endl;
    }
}
