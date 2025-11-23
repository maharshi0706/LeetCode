#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> meetingOrder(vector<int> start, vector<int> end){
        vector<int> output;
        
        vector<tuple<int,int,int>> meetings;
        for(int i = 0;i < start.size();i++){
            meetings.push_back({end[i], start[i], i+1});
        }

        sort(meetings.begin(), meetings.end());

        int prevEnd = -1;
        for(auto& meet: meetings){
            int startTime = get<1>(meet);
            int endTime = get<0>(meet);
            int idx = get<2>(meet);

            if(startTime > prevEnd){
                output.push_back(idx);
                prevEnd = endTime;
            }
        }
        return output;
    }
};


int main(){
    Solution sol;
    vector<int> start = {1,5};
    // vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {7,8};
    // vector<int> end = {2,4,5,7,9,9};
    vector<int> output = sol.meetingOrder(start, end);
    
    for(auto it: output) cout<<it<<" ";
    
    cout<<endl;
    return 0;
}