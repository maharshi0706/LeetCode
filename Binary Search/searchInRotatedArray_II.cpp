#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    bool binarySearch(int low, int high, int target, vector<int>& nums){
        if(low > high) return false;

        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return true;

        // Check if low == mid == high -> shrink search space
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            // low++;
            // high--;
            return binarySearch(low+1, high-1, target, nums);
        }

        // Find sorted half of array
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target < nums[mid]) return binarySearch(low, mid - 1, target, nums);

            else return binarySearch(mid + 1, high, target, nums);
        }

        else{
            if(nums[mid] < target && target <= nums[high]) return binarySearch(mid + 1, high, target, nums);

            else return binarySearch(low, mid - 1, target, nums);
        }
    }

    bool search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, target, nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,5,6,0,0,1,2};
    cout<<sol.search(nums, 4)<<endl;
    return 0;
}