#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        int contentChildren = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                contentChildren += 1;
                i++;
                j++;
            }
            else j++;
        }
        return contentChildren;
    }
};

int main(){
    Solution sol;
    // vector<int> greed = {3,3,3};
    vector<int> greed = {1,2};
    // vector<int> sizeOfCookies = {1,1};
    vector<int> sizeOfCookies = {1,2,3};
    cout<<sol.findContentChildren(greed, sizeOfCookies)<<endl;
    return 0;
}