#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, vector<int>& nums, int ans){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);

        // Optimization -> If half is sorted, then low will always be smallest element -> compare with ans
        if(nums[low] <= nums[high]){
            if(nums[low] < ans) ans = nums[low];
            return ans;
        }

        // Find sorted half
        if(nums[low] <= nums[mid]){
            if(nums[low] < ans) ans = nums[low];
            return binarySearch(mid + 1, high, nums, ans);
        }
        else{
            if(nums[mid] < ans) ans = nums[mid];
            return binarySearch(low, mid - 1, nums, ans);
        }
    }
    int findMinimum(vector<int>& nums){
        int ans = INT32_MAX;
        ans =  binarySearch(0, nums.size() - 1, nums, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,0,1,2};
    int res = sol.findMinimum(nums);
    cout<<res<<endl;
    return 0;
}