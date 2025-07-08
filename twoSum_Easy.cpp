#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        unordered_map<int, int> visitedValues;
        for(int i = 0;i < nums.size();i++){
            if(visitedValues.count(target-nums[i]) == 1) return {i, visitedValues[target-nums[i]]}; 

            visitedValues[nums[i]] = i;
        }
        return {}; // For syntax 
    }
};


int main(){
    Solution sol;
    int target = 6;
    vector<int> nums = {3,2,3};
    vector<int> output = sol.twoSum(nums, target);
    for(auto num: output){
        cout<<num<<endl;
    }
    return 0;
}