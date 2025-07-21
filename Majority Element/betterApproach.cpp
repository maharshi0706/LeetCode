#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementCount;
        for(int i = 0;i < nums.size();i++){
            elementCount[nums[i]]++;
            if(elementCount[nums[i]] > ((nums.size()-1) / 2)){
                return nums[i];
            }
        }
        return 0;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {3,2,3};
    vector<int> nums = {2,2,1,1,1,2,2};
    int output = sol.majorityElement(nums);
    cout<<output<<endl;
    return 0;
}