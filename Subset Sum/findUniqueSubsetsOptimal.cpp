#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    void printSubsets(vector<int>& nums, int index, vector<int>& subsets, vector<vector<int>>& output){
        
        output.push_back(subsets);
        // Loop recursive depths
        for(int i = index;i < nums.size();i++){
            if(nums[i] == nums[i-1] && i > index) continue;

            subsets.push_back(nums[i]);
            printSubsets(nums, i + 1, subsets, output);
            subsets.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> output;
        vector<int> subsets;
        std::sort(nums.begin(), nums.end());
        printSubsets(nums, 0, subsets, output);

        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    for(auto res: result){
        for(auto idx: res){
            cout<<idx<<" ";
        }
        cout<<endl;
    }
    return 0;
}