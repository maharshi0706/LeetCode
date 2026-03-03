#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void printSubsets(vector<int>& nums, int index, vector<int>& subsets, vector<vector<int>>& output){
        // Base case
        if(nums.size() == index){
            output.push_back(subsets);
            return;
        }

        subsets.push_back(nums[index]);

        printSubsets(nums, index + 1, subsets, output);
        subsets.pop_back();
        printSubsets(nums, index + 1, subsets, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> output;
        vector<int> subsets;
        printSubsets(nums, 0, subsets, output);

        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,1};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    for(auto res: result){
        for(auto idx: res){
            cout<<idx<<" ";
        }
        cout<<endl;
    }
    return 0;
}