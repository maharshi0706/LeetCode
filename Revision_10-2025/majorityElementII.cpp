#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
    vector<int> majorityElement(vector<int>& nums){
        int element1 = INT16_MAX;
        int element2 = INT16_MAX;
        int count1 = 0, count2 = 0;
        vector<int> output;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == element1) count1++;
            else if(nums[i] == element2) count2++;

            else if(count1 == 0){
                element1 = nums[i];
                count1 = 1;
            }

            else if(count2 == 0){
                element2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto num: nums){
            if(num == element1) count1++;
            else if(num == element2) count2++;
        }

        if (count1 > (nums.size()/3)) output.push_back(element1);
        if (count2 > (nums.size()/3)) output.push_back(element2);
        return output;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1,2};
    vector<int> nums = {3,2,3};
    vector<int> output = sol.majorityElement(nums);
    for(auto it: output){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}