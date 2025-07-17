#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {3,3,3,3,3};
    // vector<int> nums = {3,1,3,4,2};
    // vector<int> nums = {1,3,4,2,2};
    int duplicate = sol.findDuplicate(nums);
    cout<<duplicate<<endl;
    return 0;

}