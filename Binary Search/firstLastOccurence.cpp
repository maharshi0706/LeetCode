#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int lowerBound(int low, int high, int target, int LB, vector<int>& nums){
        if(low > high) return LB;

        int mid = low + ((high - low) / 2);
        if(nums[mid] >= target) return lowerBound(low, mid - 1, target, mid, nums);

        return lowerBound(mid + 1, high, target, LB, nums);
    }

    int upperBound(int low, int high, int target, int UB, vector<int>& nums){
        if(low > high) return UB;

        int mid = low + ((high - low) / 2);
        if(nums[mid] > target) return upperBound(low, mid - 1, target, mid, nums);

        return upperBound(mid + 1, high, target, UB, nums);
    }

    pair<int, int> firstLastOccurence(int target, vector<int>& nums){
        pair<int, int> firstAndLast;

        int LB = lowerBound(0, nums.size() - 1, target, nums.size(), nums);
        if (LB == nums.size() || nums[LB] != target){
            return {-1, -1};
        }
        int UB = upperBound(0, nums.size() - 1, target, nums.size(), nums);
        return {LB, UB - 1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,4,6,8,8,8,11,13};
    pair<int, int> firstAndLast = sol.firstLastOccurence(8, nums);
    cout<<firstAndLast.first<<"\t"<<firstAndLast.second<<endl;
    return 0;
}