#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapValues;
        for(const string& s: strs){
            string value = s;
            sort(value.begin(), value.end());
            mapValues[value].push_back(s);
        }

        vector<vector<string>> output;
        for(auto& keyValue: mapValues){
            output.push_back(move(keyValue.second));
        }
        return output;

    }
};

int main(){
    Solution sol;
    vector<string> strs = {""};
    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> output = sol.groupAnagrams(strs);
    for(auto& vec: output){
        for(auto& str: vec){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}