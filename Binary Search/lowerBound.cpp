#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int findLowerBound(int low, int high, int target, int ans, vector<int>& nums){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(nums[mid] >= target) return findLowerBound(low, mid - 1, target, mid, nums);

        return findLowerBound(mid + 1, high, target, ans, nums);

    }

    int solve(int target, vector<int>& nums){
        // define default answer if no element found >= target -> length of nums
        int ans = nums.size();
        ans =  findLowerBound(0, nums.size() - 1, target, ans, nums);
        return ans;
    };
};

int main(){
    Solution sol;
    vector<int> nums = {1,5,8,15,19};
    int res = sol.solve(8, nums);
    cout<<res<<endl;
    return 0;
}