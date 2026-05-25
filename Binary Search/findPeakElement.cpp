#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, vector<int>& nums){
        // Required base case -> will NEVER be executed
        if(low > high) return -1; 

        int mid = low + ((high - low) / 2);
        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;

        // Reduce search space
        if(nums[mid] < nums[mid - 1]) return binarySearch(low, mid - 1, nums);

        return binarySearch(mid + 1, high, nums);
    }

    int findPeak(vector<int>& nums){
        // Handle edge cases -> First or Last element or single element
        if(nums.size() == 1 || nums[0] > nums[1]) return 0;

        else if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        else return binarySearch(1, nums.size() - 2, nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,5,1,2,1};
    cout<<sol.findPeak(nums)<<endl;
    return 0;
}