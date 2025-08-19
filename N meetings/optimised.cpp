#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int s;
    int e;
    int pos;
};

class Solution {
public:
    bool static comparator(struct meeting m1, meeting m2){
        if(m1.e < m2.e) return true;
        else if(m1.e > m2.e) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }
    int maxmeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
        struct meeting meets[n];
        for(int i = 0;i < n;i++){
            meets[i].s = start[i];
            meets[i].e = end[i];
            meets[i].pos = i+1;
        }

        sort(meets, meets + n, comparator);

        vector<int> answer;
        answer.push_back(meets[0].pos);
        int limit = meets[0].e;
        for(int i = 1;i < n;i++){
            if(meets[i].s > limit){
                answer.push_back(meets[i].pos);
                limit = meets[i].e;
            }
        }
        for(auto it: answer){
            cout<<it<<" ";
        }
        cout<<endl;
        return answer.size();
    }
};


int main(){
    Solution sol;
    vector<int> start = {10, 12, 20};
    // vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {20, 25, 30};
    cout<<sol.maxmeetings(start, end)<<endl;
    return 0;
}