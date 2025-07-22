#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> nums, int target){
        unordered_map<int,int> checkedValues;
        for(int i = 0;i < nums.size();i++){
            if(checkedValues.count(target - nums[i]) == 1) return {i,checkedValues[target-nums[i]]};

            checkedValues[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution sol;
    vector<int> output = sol.twoSum({3,2,4},6);
    for(auto num: output){
        cout<<num<<" ";
    }
    return 0;
}