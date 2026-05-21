#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, int ans, int idx, vector<int>& nums){
        if(low > high) return idx;

        int mid = low + ((high - low) / 2);
        if(nums[low] <= nums[high]){
            if(nums[low] < ans) {
                ans = nums[low];
                idx = low;
            }
            return idx;
        }

        // Find sorted half
        if(nums[low] <= nums[mid]) {
            if(nums[low] < ans){
                return binarySearch(mid + 1, high, nums[low], low, nums);
            }
        }
        return binarySearch(low, mid - 1, nums[mid], mid, nums);
    }

    int numOfTimes(vector<int>& nums){
        int ans = INT_MAX;
        int idx = -1;
        idx = binarySearch(0, nums.size() - 1, ans, idx, nums);
        
        return idx;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    cout<<sol.numOfTimes(nums)<<endl;
    return 0;
}