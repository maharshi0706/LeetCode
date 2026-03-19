#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:

    void findCombinations(vector<int>& candidates, int idx, int diff, vector<int> answer, vector<vector<int>>& output){
        // Base case -> if target reached
        if(diff == 0) {
            output.push_back(answer);
            return;
        }

        // Iterate each candidate
        for(int i = idx;i < candidates.size();i++){
            // Check if curr candidate > diff ? stop : add || unique check (if visiting same branch of recursion tree)
            if(candidates[i] > diff || (i > idx && candidates[i] == candidates[i-1])) continue;

            answer.push_back(candidates[i]);
            findCombinations(candidates, i + 1, diff - candidates[i], answer, output);
            answer.pop_back();
        }        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> answer;
        vector<vector<int>> output;
        std::sort(candidates.begin(), candidates.end());
        findCombinations(candidates, 0, target, answer, output);

        return output;

    }
};


int main(){
    Solution sol;
    int target = 5;
    vector<int> candidates = {2,5,2,1,2};
    vector<vector<int>> output = sol.combinationSum2(candidates, target);
    for(auto answer: output){
        for(auto ans: answer){
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}