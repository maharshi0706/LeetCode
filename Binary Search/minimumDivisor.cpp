#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    bool checkDivisor(int divisor, int threshold, vector<int>& nums){
        int res = 0;
        for(int i = 0;i < nums.size();i++){
            res += ceil((double) nums[i] / (double) divisor);
        }
        return res <= threshold;
    }

    int binarySearch(int low, int high, int ans, int threshold, vector<int>& nums){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(checkDivisor(mid, threshold, nums)) return binarySearch(low, mid - 1, mid, threshold, nums);

        return binarySearch(mid + 1, high, ans, threshold, nums);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        return binarySearch(1, *max_element(nums.begin(), nums.end()), -1, threshold, nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {44,22,33,11,1};
    cout<<sol.smallestDivisor(nums, 5)<<endl;
    return 0;
}