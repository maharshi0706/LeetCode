#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> output;
        unordered_set<int> added;
        unordered_map<int, int> countElement;
        for(int i = 0;i < nums.size();i++){
            countElement[nums[i]]++;
            if(countElement[nums[i]] > (nums.size() / 3) && added.find(nums[i]) == added.end()) {
                output.push_back(nums[i]);
                added.insert(nums[i]);
            }
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1};
    // vector<int> nums = {3,2,3};
    vector<int> output = sol.majorityElement(nums);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}