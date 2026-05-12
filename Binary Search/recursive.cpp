#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, int target, vector<int>& nums){
        // Base Case
        if(low > high) return -1;

        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return mid;

        else if (nums[mid] > target) return binarySearch(low, mid - 1, target, nums);
        
        else return binarySearch(mid + 1, high, target, nums);
    }


    int findElement(int target, vector<int>& nums){
        int result = binarySearch(0, nums.size() - 1, target, nums);

        return result;

    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,3,4,6,7,10,11,15};
    int result = sol.findElement(11, nums);
    cout<<result<<endl;
    return 0;
}