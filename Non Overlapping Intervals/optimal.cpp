#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Intervals{
    int start;
    int end;
};

class Solution{
    public:

    bool static comparator(Intervals i1, Intervals i2){
        if(i1.end < i2.end) return true;
        else return false;
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        struct Intervals allIntervals[intervals.size()];
        for(int i = 0;i < intervals.size();i++){
            allIntervals[i].start = intervals[i][0];
            allIntervals[i].end = intervals[i][1];
        }

        sort(allIntervals, allIntervals+(intervals.size()), comparator);

        int count = 0;
        int prevEnd = allIntervals[0].end;
        for(int i = 1;i < intervals.size();i++){
            if(allIntervals[i].start < prevEnd) {
                count += 1;
            }
            else prevEnd = allIntervals[i].end;
            cout<<allIntervals[i].start<<" "<<allIntervals[i].end<<endl;
        }
        // cout<<endl;
        return count;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{-100,-2},{5,7}};
    // vector<vector<int>> intervals = {{1,100},{11,22},{1,11},{2,12}};
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout<<sol.eraseOverlapIntervals(intervals)<<endl;
    return 0;
}