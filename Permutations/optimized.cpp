#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    void getPermutations(int pos, vector<int> nums, vector<vector<int>>& output){
        // Base condition -> if pos == nums.size()
        if(pos == nums.size()){
            output.push_back(nums);
            return;
        }

        for(int i = pos;i < nums.size();i++){
            std::swap(nums[pos], nums[i]);
            getPermutations(pos+1, nums, output);
            std::swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> output;

        getPermutations(0, nums, output);
        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> output = sol.permute(nums);
    for(auto num: output){
        for(auto it: num){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}