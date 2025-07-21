// Moore's Voting Algorithm
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currElement;
        for(int i = 0;i < nums.size();i++){
            if(count == 0) currElement = nums[i];
            if(currElement == nums[i]) count += 1;

            else count -= 1;
        }
        return currElement;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {3,2,3};
    // vector<int> nums = {2,2,1,1,1,2,2};
    int output = sol.majorityElement(nums);
    cout<<output<<endl;
    return 0;
}