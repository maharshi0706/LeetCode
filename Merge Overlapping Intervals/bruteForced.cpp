#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        // for(auto it:intervals){
        //     for(auto idx: it){
        //         cout<<idx<<",";
        //     }
        //     cout<<"     ";
        // }
        // cout<<endl<<endl;
        
        
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        vector<vector<int>> output;
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] <= prevEnd) {

                // Check which end value is greater
                if(intervals[i][1] < prevEnd){
                    output.push_back(intervals[i-1]);
                    // intervals.erase(intervals.begin()+i);
                }
                else{
                    // intervals[i][0] = prevStart;
                    output.push_back({prevStart,intervals[i][1]});
                    prevEnd = intervals[i][1];
                    // intervals.erase(intervals.begin()+(i-1));
                }
            }
            else {
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
                output.push_back({prevStart,prevEnd});
            }
            
        }
        int first = output[0][0];
        for(int i = 1;i < output.size();i++){
            if(output[i][0] == first) output.erase(output.begin()+(i-1));

            else first = output[i][0];
        }
        for(auto it: output){
            for(auto i: it){
                cout<<i<<",";
            }
            cout<<endl;
        }
        return output;
    }
};


int main(){
    Solution sol;
    // vector<vector<int>> intervals = {{1,4},{4,5}};
    // vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> output = sol.merge(intervals);
    // for(auto it:output){
    //     for(auto idx: it){
    //         cout<<idx<<",";
    //     }
    //     cout<<"     ";
    // }
    
    return 0;
}