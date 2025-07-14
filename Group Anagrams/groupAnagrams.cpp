#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2){
            return {strs};
        }


        vector<string> sortedStrs; // Alphabetically sorted strs
        vector<vector<string>> output; // Final output
        unordered_map<string, vector<string>> mapValues; // HashMap to check similar anagrams
        
        copy(strs.begin(), strs.end(), back_inserter(sortedStrs)); 
        for(auto& str: sortedStrs){
            sort(str.begin(), str.end());
        }
        for(int i = 0;i < sortedStrs.size();i++){
            if(mapValues.count(sortedStrs[i]) == 0) mapValues.emplace(sortedStrs[i], vector<string>());

            mapValues[sortedStrs[i]].push_back(strs[i]);
        }
        for(const auto& keyValue: mapValues){
            output.push_back(keyValue.second);
        }

        return output;

    }
};

int main(){
    Solution sol;
    vector<string> strs = {"a"};
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