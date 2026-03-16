#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    void getCombinationSum(vector<int>& candidates, int idx, int diff, vector<int>& answer, vector<vector<int>>& output){
        
        if(diff == 0){
            output.push_back(answer);
            return;
        }
        
        // Loop input
        for(int i = idx;i < candidates.size();i++){
            // If diff < [i] -> stop
            if(candidates[i] > diff){
                break;
            }
            answer.push_back(candidates[i]);
            getCombinationSum(candidates, i, diff - candidates[i], answer, output);
            answer.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> answer;
        std::sort(candidates.begin(), candidates.end());
        getCombinationSum(candidates, 0, target, answer, output);

        for(auto answer: output){
            for(auto ans: answer){
                cout<<ans<<" ";
            }
            cout<<endl;
        }
        
    }
};

int main(){
    Solution sol;
    int target = 8;
    vector<int> candidates = {2,3,5};
    sol.combinationSum(candidates, target);
    return 0;
}