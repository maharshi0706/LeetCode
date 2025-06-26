#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currSum = 0;
        int sizeSubArray = INT_MAX;
        for(int right = 0;right < nums.size();right++){
            currSum += nums[right];
            cout<<"\nCURR SUM BEFORE: "<<currSum<<endl;
            cout<<"RIGHT POS: "<<right<<endl;
            while(currSum >= target){
                cout<<" LEFT POS: "<<left<<endl;
                sizeSubArray = min(sizeSubArray, right-left+1);
                currSum -= nums[left++];
            }
            cout<<"CURR SUM AFTER: "<<currSum<<endl;
        }
        return sizeSubArray == INT_MAX ? 0 : sizeSubArray;
    }
};

int main(){
    Solution sol;
    int target = 10;
    vector<int> nums = {1,4,4};
    // vector<int> nums = {2,3,1,2,4,3};
    cout<<sol.minSubArrayLen(target, nums)<<endl;
    return 0;
}