#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        string S; 
        cin>>S;
        int count = 0;
        for(int i = 0;i < N;i++){
            if(S[i] == S[i+1]) count += 1;
        }
        cout<<count<<endl;
    }
}
