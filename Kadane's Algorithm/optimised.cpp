#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; // REDUNDANT -> below code will handle such cases :)

        int currSum = 0;
        int totalSum = INT32_MIN;
        for(int i = 0;i < nums.size();i++){
            currSum += nums[i];
            totalSum = max(currSum, totalSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return totalSum;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {5};
    // vector<int> nums = {-2,1};
    // vector<int> nums = {-2,-1,-3,-4};
    // vector<int> nums = {5,4,-1,7,8};
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int output = sol.maxSubArray(nums);
    cout<<output<<endl;
    return 0;
}