#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, int ans, vector<int>& nums){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);

        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

        // Eliminate halves -> (even, odd) to left of single element && (odd, even) to right
        if(mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 == 1 && nums[mid] == nums[mid - 1]){
            return binarySearch(mid + 1, high, ans, nums);
        }
        return binarySearch(low, mid - 1, ans, nums);
    }

    int singleNonDuplicate(vector<int>& nums){
        // Edge cases
        if(nums.size() == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];

        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];

        int res = binarySearch(1, nums.size() - 2, -1,  nums);

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,3,7,7,10,11,11};
    cout<<sol.singleNonDuplicate(nums)<<endl;
    return 0;
}