#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, int target, int ans, vector<int>& nums){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return mid;

        // Find Sorted half of array
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                return binarySearch(low, mid - 1, target, ans, nums);
            }
            else{
                return binarySearch(mid + 1, high, target, ans, nums);
            }
        }

        else{
            if(nums[mid] <= target && target <= nums[high]){
                return binarySearch(mid + 1, high, target, ans, nums);
            }
            else{
                return binarySearch(low, mid - 1, target, ans, nums);
            }
        }
    }

    int searchInRotatedArray(int target, vector<int>& nums){
        int answer = binarySearch(0, nums.size() - 1, target, -1, nums);

        return answer;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int res = sol.searchInRotatedArray(5, nums);
    cout<<res<<endl;
    return 0;
}