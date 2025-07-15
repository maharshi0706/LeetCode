#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool toSort = true;
        int n = nums.size()-1;
        for(int i = n-1;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                for(int j = n;j > i;j--){
                    if (nums[j] > nums[i]){
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        break;
                    }
                }
                reverse(nums.begin()+i+1, nums.end());
                toSort = false;
                break;
            }
        }
        if(toSort) sort(nums.begin(), nums.end());
        
        for(auto it: nums){
            cout<<it<<" ";
        }

    }
};


int main(){
    Solution sol;
    vector<int> nums = {2,3,1};
    // vector<int> nums = {1,2,3};
    sol.nextPermutation(nums);
    return 0;
}