#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> output; 
        for(int i = 0;i < intervals.size();i++){
            if(output.empty()) output.push_back(intervals[i]);
            
            else if(intervals[i][0] <= output[output.size()-1][1])  output[output.size()-1][1] = max(intervals[i][1], output[output.size()-1][1]);

            else output.push_back(intervals[i]);

        }
        return output;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,4},{4,5}};
    // vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> output = sol.merge(intervals);
    for(auto it:output){
        for(auto idx: it){
            cout<<idx<<",";
        }
        cout<<endl;
    }
    
    return 0;
}