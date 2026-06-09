#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool checkIfCowsFit(int currentDistance, int k, vector<int>& nums){
        int cowsFit = 1;
        int lastCow = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] - lastCow >= currentDistance){
                lastCow = nums[i];
                cowsFit++;
            }
        }

        return cowsFit >= k;
    }

    int binarySearch(int low, int high, int ans, int k, vector<int>& nums){
        if (low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(checkIfCowsFit(mid, k, nums)) return binarySearch(mid + 1, high, mid, k, nums);

        return binarySearch(low, mid - 1, ans, k, nums);
    }

    int aggressiveCows(vector<int> &nums, int k) {
        int high = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());

        std::sort(nums.begin(), nums.end());
        return binarySearch(1, high, 1, k, nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,3,4,7,10,9};
    cout<<sol.aggressiveCows(nums, 4)<<endl;
    return 0;
}