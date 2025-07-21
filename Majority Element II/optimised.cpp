// only 2 elements can have count greater than n/3 - INTUITION
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> output;
        int count1 = 0, count2 = 0;
        int element1 = INT16_MIN;
        int element2 = INT16_MIN;
        for(int i = 0;i < nums.size();i++){
            if(count1 == 0 && element2 != nums[i]) {
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2 == 0 && element1 != nums[i]){
                count2 = 1;
                element2 = nums[i];
            }
            else if(element1 == nums[i]) count1++;

            else if(element2 == nums[i]) count2++;

            else{
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == element1) count1++;
            if(nums[i] == element2) count2++;
        }
        if(count1 > (nums.size()/3)) output.push_back(element1);
        if(count2 > (nums.size()/3)) output.push_back(element2);
        
        return output;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2};
    // vector<int> nums = {3,2,3};
    vector<int> output = sol.majorityElement(nums);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}