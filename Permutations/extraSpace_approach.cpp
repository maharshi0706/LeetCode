#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void getPermutations(vector<int> answer, vector<int> isTaken, vector<int>& nums, vector<vector<int>>& output){
        // Base condition -> if answer.size == nums.size
        if(answer.size() == nums.size()){
            output.push_back(answer);
            return;
        }
        
        int idx = 0;
        while(idx < isTaken.size()) {
            if(isTaken[idx] == 0) {
                answer.push_back(nums[idx]);
                isTaken[idx] = 1;
                getPermutations(answer, isTaken, nums, output);
                answer.pop_back();
                isTaken[idx] = 0;
            }
            idx++;
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<int> answer;
        vector<int> isTaken(nums.size(), 0);
        vector<vector<int>> output;

        getPermutations(answer, isTaken, nums, output);
        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> output = sol.permute(nums);
    for(auto num: output){
        for(auto it: num){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}