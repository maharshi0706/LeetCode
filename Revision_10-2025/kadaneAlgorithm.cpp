#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int currSum = 0;
        int maxSum = 0;
        int maxSmallestElement = -2147483648;
        for(int i = 0;i < nums.size();i++){
            if(currSum + nums[i] > 0) currSum += nums[i];

            else currSum = 0;

            maxSum = max(currSum, maxSum);
            maxSmallestElement = max(nums[i], maxSmallestElement);

        }
        return maxSum == 0 ? maxSmallestElement : maxSum;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {-2,-1};
    // vector<int> nums = {5,4,-1,7,8};
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = sol.maxSubArray(nums);
    cout<<maxSum<<endl; 
    return 0;
}