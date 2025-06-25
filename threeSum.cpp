#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        // for(auto num: nums){
        //     cout<<num;
        // }
        // cout<<endl;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

            int target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    output.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,0,0};
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> output = sol.threeSum(nums);
    for (const auto& innerVector : output) {
    // Iterate through each element in the inner vector
    for (int element : innerVector) {
        cout << element << " ";
    }
    cout << endl; // Move to the next line after each inner vector
    }
    return 0;
}