#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearchFloor(int low, int high, int target, int ans, vector<int>& nums){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(nums[mid] <= target) return binarySearchFloor(mid + 1, high, target, nums[mid], nums);

        return binarySearchFloor(low, mid - 1, target, ans, nums);
    }

    int getFloor(int target, vector<int>& nums){
        // Default answer incase no element <= target
        int ans = -1;
        ans = binarySearchFloor(0, nums.size() - 1, target, ans, nums);
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,7,10,12,14};
    int floorResult = sol.getFloor(0, nums);
    cout<<floorResult<<endl;
    return 0;
}