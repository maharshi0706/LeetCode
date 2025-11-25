#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findContentChildren(vector<int> g, vector<int> s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int n = g.size();
        int m = s.size();
        int contentChildren = 0;

        while(i < n && j < m){
            if(s[j] >= g[i]){
                contentChildren += 1;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return contentChildren;
    }
};

int main(){
    Solution sol;
    cout<<sol.findContentChildren({1,2},{1,2,3})<<endl;
    return 0;
}